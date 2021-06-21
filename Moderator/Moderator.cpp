#include "Moderator.h"

HANDLE muthandle;
string GlobalBuffer;

// Part of boyer moore
void otherArrayFunc(string str, int otherArray[256])
{
	for (int i = 0; i < 256; i++)
	{
		otherArray[i] = -1;
	}

	for (int i = 0; i < str.size(); i++)
	{
		otherArray[(int)str[i]] = i;
	}
}

// Boyer moore algoritm
int BMSearch(string main, string find, vector<int>& result)
{
	int otherArray[256];

	otherArrayFunc(find, otherArray);
	int count = 0;
	int index = 0;
	while (index <= (main.size() - find.size()))
	{
		int i = find.size() - 1;

		while (i >= 0 && find[i] == main[index + i])
		{
			i--;
		}

		if (i < 0)
		{
			for (int j = 0; j < find.size(); j++)
			{
				result.push_back(index + j);
			}
			count++;
			index += (index + find.size() < main.size()) ? find.size() - otherArray[main[index + find.size()]] : 1;
		}
		else
		{
			index += (i - otherArray[main[index + i]]);
		}
	}
	return count;
}

//connection to server
int ConnectToServer(SOCKET& ConnectSocket)
{
	WSADATA wsaData;
	struct addrinfo hints, * result = NULL, * ptr = NULL;
	int iResult;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL;ptr = ptr->ai_next)
	{

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET)
		{
			WSACleanup();
			return 1;
		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET)
	{
		WSACleanup();
		return 1;
	}

	return 0;
}

// Send an initial buffer
int SentMsg(SOCKET& ConnectSocket, string msg)
{
	WaitForSingleObject(muthandle, INFINITE);

	int iResult = send(ConnectSocket, msg.c_str(), msg.size(), 0);

	if (iResult == SOCKET_ERROR)
	{
		MessageBox::Show("Send failed with error", "Sending error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	ReleaseMutex(muthandle);

	return 0;
}

// Receive until the peer closes the connection
unsigned int WINAPI GetMsg(LPVOID Socket)
{
	int iResult;
	string text;
	char recvbuf[DEFAULT_BUFLEN];

	SOCKET ConnectSocket = (SOCKET)Socket;
	while (true)
	{
		iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
		if (iResult > 0)
		{
			recvbuf[iResult] = 0;
			text = recvbuf;
			if (SwitchDo(ConnectSocket, text) != 0)
			{
				MessageBox::Show("Wrong message from server", "Message error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			if (iResult == 0)
			{
				MessageBox::Show("Server has ended", "Coonection end", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}
			else
			{
				MessageBox::Show("Receive failed with error", "Coonection end", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}
		}
	}
	return 0;
}

// Switch what to do
int SwitchDo(SOCKET& ConnectSocket, string text)
{
	int first = text.find_first_of(' ');
	string temp = text.substr(0, first);
	string msg = text.substr(first + 1, text.size());

	if (temp == "MSG")
	{
		GlobalBuffer = msg;
		return 0;
	}
	if (temp == "EDI")
	{
		SentMsg(ConnectSocket, ParseText(msg));
		return 0;
	}
	if (temp == "ERR")
	{
		MessageBox::Show(StdToSys(msg), "Error from server", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	if (temp == "INF")
	{
		MessageBox::Show(StdToSys(msg), "Informationr from server", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return 0;
	}

	return 1;
}

// Parse text
//<M> fanteak : let`s play csgo        SET <M> fanteak : let`s play csgo
//yuri : let`s play csgo        SET yuri 1 let`s play ****
string ParseText(string msg)
{
	int first = msg.find_first_of(' ');
	string temp = msg.substr(0, first);
	if (temp == "<M>")
	{
		return ("SET " + msg);
	}
	else
	{
		fstream fs;
		fs.open("LogFile.txt", fstream::out | fstream::app);
		fs << GetTime() << temp << " ";
		temp = "SET " + temp + " " + FindBW(msg.substr(first + 3, msg.size()), fs);
		fs.close();
		return temp;
	}
}

// Find bad word and delete change them to
string FindBW(string msg, fstream& fs)
{
	const int SIZE = 7;
	string badArray[] =
	{
		"csgo",
		"windows",
		"linux",
		"thread",
		"process",
		"sync",
		"network"
	};

	int count = 0;
	vector<int> result;
	for (int i = 0; i < SIZE; i++)
	{
		int temp = BMSearch(msg, badArray[i], result);
		if (temp > 0)
		{
			count += temp;
			fs << badArray[i] << " " << temp << endl;
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		msg[result[i]] = '*';
	}

	return (to_string(count) + " " + msg);
}

// Get time
string GetTime()
{
	time_t now = time(0);
	tm* gmtm = gmtime(&now);
	string result = "[";
	result += to_string(gmtm->tm_mday) + "-";
	result += to_string(gmtm->tm_mon) + "-";
	result += to_string(gmtm->tm_year) + " ";
	result += to_string(gmtm->tm_hour) + ":";
	result += to_string(gmtm->tm_min) + ":";
	result += to_string(gmtm->tm_sec) + "]: ";
	return result;
}

// Cleanup
void CloseConnect(SOCKET& ConnectSocket, HANDLE& in)
{
	WaitForSingleObject(in, INFINITE);

	CloseHandle(in);
	CloseHandle(muthandle);

	SentMsg(ConnectSocket, "QUIT");
	closesocket(ConnectSocket);

	WSACleanup();
}

//convert standart type to string to System::String^
String^ StdToSys(string str)
{
	return gcnew String(str.c_str());
}

//convert System::String^ type of string to standart string
const string SysToStd(String^ sysStr)
{
	return (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sysStr)).ToPointer();
}