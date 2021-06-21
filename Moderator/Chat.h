#pragma once
#include "Moderator.h"

namespace Moderator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	SOCKET ConnectSocket;
	HANDLE inHandle;

	/// <summary>
	/// Summary for Chat
	/// </summary>
	public ref class Chat : public System::Windows::Forms::Form
	{
	public:
		Chat()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Chat(SOCKET& Socket) : Chat()
		{
			ConnectSocket = Socket;
			timer1->Interval = 500;
		}
		~Chat()
		{
			if (components)
			{
				delete components;
			}
			CloseConnect(ConnectSocket, inHandle);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lavender;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(640, 485);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Chat::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Enabled = false;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(13, 13);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(827, 467);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(13, 486);
			this->textBox2->MaxLength = 50;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(582, 38);
			this->textBox2->TabIndex = 21;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(602, 487);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 29);
			this->label1->TabIndex = 22;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Chat::timer1_Tick);
			// 
			// Chat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(857, 536);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Chat";
			this->Text = L"Chat";
			this->Load += gcnew System::EventHandler(this, &Chat::Chat_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = "";
		if (textBox2->Text == "")
		{
			label1->Text = "*";
		}
		else
		{
			string msg = "SEND ";
			msg += SysToStd(textBox2->Text);
			SentMsg(ConnectSocket, msg);
			textBox2->Text = "";
		}
	}

	private: System::Void Chat_Load(System::Object^ sender, System::EventArgs^ e) {
		inHandle = (HANDLE)_beginthreadex(0, 0, GetMsg, (LPVOID)ConnectSocket, 0, 0);
		extern HANDLE muthandle;
		muthandle = CreateMutex(0, FALSE, 0);
		timer1->Start();
	}

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	extern string GlobalBuffer;
	if (GlobalBuffer != "")
	{
		richTextBox1->Text += StdToSys(GlobalBuffer);
		GlobalBuffer = "";
	}
}

};
}
