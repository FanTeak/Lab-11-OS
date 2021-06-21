#include "Login.h"
#include "Registration.h"
#include "Chat.h"
#include <Windows.h>

using namespace Moderator;

[System::STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Login);

	return 0;
}