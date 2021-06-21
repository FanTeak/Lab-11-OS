#pragma once
#include "Moderator.h"
#include "Registration.h"
#include "Chat.h"

namespace Moderator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ LoginCheck;
	private: System::Windows::Forms::Label^ PasswordCheck;

	private: System::Windows::Forms::Button^ button2;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->LoginCheck = (gcnew System::Windows::Forms::Label());
			this->PasswordCheck = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Cornsilk;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 42);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Login";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Cornsilk;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 42);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Password";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(151, 12);
			this->textBox1->MaxLength = 10;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(232, 38);
			this->textBox1->TabIndex = 19;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(151, 67);
			this->textBox2->MaxLength = 10;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(232, 38);
			this->textBox2->TabIndex = 20;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lavender;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 120);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(371, 42);
			this->button1->TabIndex = 29;
			this->button1->Text = L"Sign in";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// LoginCheck
			// 
			this->LoginCheck->AutoSize = true;
			this->LoginCheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LoginCheck->ForeColor = System::Drawing::Color::Red;
			this->LoginCheck->Location = System::Drawing::Point(385, 12);
			this->LoginCheck->Name = L"LoginCheck";
			this->LoginCheck->Size = System::Drawing::Size(0, 29);
			this->LoginCheck->TabIndex = 30;
			// 
			// PasswordCheck
			// 
			this->PasswordCheck->AutoSize = true;
			this->PasswordCheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PasswordCheck->ForeColor = System::Drawing::Color::Red;
			this->PasswordCheck->Location = System::Drawing::Point(385, 67);
			this->PasswordCheck->Name = L"PasswordCheck";
			this->PasswordCheck->Size = System::Drawing::Size(0, 29);
			this->PasswordCheck->TabIndex = 31;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Lavender;
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(12, 168);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(371, 42);
			this->button2->TabIndex = 32;
			this->button2->Text = L"Create new account";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Login::button2_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(420, 219);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->PasswordCheck);
			this->Controls->Add(this->LoginCheck);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		PasswordCheck->Text = "";
		LoginCheck->Text = "";
		string text = "LOGIN ";
		if (textBox1->Text != "")
		{
			text += SysToStd(textBox1->Text) + " ";
			if (textBox2->Text != "")
			{
				text += SysToStd(textBox2->Text);

				SOCKET ConnectSocket = INVALID_SOCKET;
				if (ConnectToServer(ConnectSocket) != 0)
				{
					MessageBox::Show("Unable to connect to server!", "Connect", MessageBoxButtons::OK, MessageBoxIcon::Error);
					WSACleanup();
				}
				else
				{
					SentMsg(ConnectSocket, text);
					char recvbuf[DEFAULT_BUFLEN];
					int iResult;
					string recvText;
					while (true)
					{
						iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
						if (iResult > 0)
						{
							recvbuf[iResult] = 0;
							recvText = recvbuf;
							if (recvText.substr(0, 3) == "INF")
							{
								MessageBox::Show(StdToSys(recvText.substr(4, recvText.size())), "Connect", MessageBoxButtons::OK, MessageBoxIcon::Information);
								this->Hide();
								Chat^ chatForm = gcnew Chat(ConnectSocket);
								chatForm->ShowDialog();
								Application::Exit();
							}
							else
							{
								MessageBox::Show(StdToSys(recvText.substr(4, recvText.size())), "Error connection", MessageBoxButtons::OK, MessageBoxIcon::Error);
							}
							break;
						}
					}
				}
			}
			else
			{
				PasswordCheck->Text = "*";
			}
		}
		else
		{
			LoginCheck->Text = "*";
		}
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Hide();
	Registration^ regForm = gcnew Registration();
	regForm->ShowDialog();
}

};
}
