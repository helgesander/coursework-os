#pragma once

#define _WINSOCKAPI_
#define _WIN32_WINNT 0x501

#pragma comment(lib, "Ws2_32.lib")

#include <cstdlib>
#include <Windows.h>
#include <WinSock2.h>
#include <string>

#define FIRST_PORT 12344
#define SECOND_PORT 12345

namespace client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для App
	/// </summary>
	public ref class App : public System::Windows::Forms::Form
	{
	public:
		App(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~App()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;
	private: int first_client = 0;
	private: int second_client = 0;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Взять инфу с первого сервера";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &App::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(237, 31);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(186, 41);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Взять инфу со второго сервера";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &App::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(24, 127);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ответ сервера:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(27, 156);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(403, 22);
			this->textBox1->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(27, 196);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 26);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Выйти";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &App::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(153, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Server connection error";
			this->label2->Visible = false;
			// 
			// App
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(449, 118);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"App";
			this->Text = L"App";
			this->Load += gcnew System::EventHandler(this, &App::App_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		const char* env_var = std::getenv("IP_ADDRESS_SECOND_SERVER");;
		std::string env_ip_second(env_var ? env_var : "");
		if (env_ip_second.empty()) {
			this->label2->Visible = true;
			this->label2->Text = L"Something wrong with enviroment variables, cannot get ip address";
			this->label2->Location = System::Drawing::Point(71, 86);
		}
		else this->ClientSize = System::Drawing::Size(465, 272);
		// TODO: fix connection to second server
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (first_client != 0) closesocket(first_client);
		if (second_client != 0) closesocket(second_client);
		exit(0);
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->label2->Visible = false;
	const char* env_var_ip = std::getenv("IP_ADDRESS_FIRST_SERVER");
	this->ClientSize = System::Drawing::Size(465, 272);
	std::string env_ip_first(env_var_ip ? env_var_ip : "");
	if (env_ip_first.empty()) {
		this->label2->Visible = true;
		this->label2->Text = L"Something wrong with enviroment variables, cannot get ip address";
		this->label2->Location = System::Drawing::Point(71, 86);
	}
	else {
		if (first_client == 0) {
			if ((first_client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
				this->label2->Visible = true;
				this->label2->Text = L"Error connect to first server";
				this->label2->Location = System::Drawing::Point(71, 86);
			}
			else
			{
				
			}
		}
		else
		{

		}

		this->ClientSize = System::Drawing::Size(465, 272);
	}

}
private: System::Void App_Load(System::Object^ sender, System::EventArgs^ e) {
	int status, valread, client_fd;
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		this->label2->Visible = true;
	}
	this->label2->Text = L"Something wrong with enviroment variables, cannot get ip address";
	this->label2->Location = System::Drawing::Point(71, 86);
}
};
}
