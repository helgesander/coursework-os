#pragma once

#include "client.h"
#include <msclr/marshal.h>

namespace client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;

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
	private: System::Windows::Forms::Button^ firstServerButton;
	private: System::Windows::Forms::Button^ secondServerButton;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ exitButton;

	private: System::Windows::Forms::Label^ errorLabel;

	private: System::Windows::Forms::TextBox^ ipAddressTextBox;
	private: System::Windows::Forms::Label^ ipLabel;



	private: System::Windows::Forms::Button^ buttonWithIPAddress;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Button^ getInfoButton;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;

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
			this->firstServerButton = (gcnew System::Windows::Forms::Button());
			this->secondServerButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->errorLabel = (gcnew System::Windows::Forms::Label());
			this->ipAddressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ipLabel = (gcnew System::Windows::Forms::Label());
			this->buttonWithIPAddress = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->getInfoButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// firstServerButton
			// 
			this->firstServerButton->Location = System::Drawing::Point(26, 31);
			this->firstServerButton->Name = L"firstServerButton";
			this->firstServerButton->Size = System::Drawing::Size(186, 41);
			this->firstServerButton->TabIndex = 0;
			this->firstServerButton->Text = L"Взять инфу с первого сервера";
			this->firstServerButton->UseVisualStyleBackColor = true;
			this->firstServerButton->Visible = false;
			this->firstServerButton->Click += gcnew System::EventHandler(this, &App::firstServerButton_Click);
			// 
			// secondServerButton
			// 
			this->secondServerButton->Location = System::Drawing::Point(237, 31);
			this->secondServerButton->Name = L"secondServerButton";
			this->secondServerButton->Size = System::Drawing::Size(186, 41);
			this->secondServerButton->TabIndex = 1;
			this->secondServerButton->Text = L"Взять инфу со второго сервера";
			this->secondServerButton->UseVisualStyleBackColor = true;
			this->secondServerButton->Visible = false;
			this->secondServerButton->Click += gcnew System::EventHandler(this, &App::secondServerButton_Click);
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
			this->label1->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(27, 156);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(403, 22);
			this->textBox1->TabIndex = 3;
			this->textBox1->Visible = false;
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(27, 196);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(121, 26);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"Выйти";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Visible = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &App::exitButton_Click);
			// 
			// errorLabel
			// 
			this->errorLabel->AutoSize = true;
			this->errorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->errorLabel->ForeColor = System::Drawing::Color::Red;
			this->errorLabel->Location = System::Drawing::Point(91, 104);
			this->errorLabel->Name = L"errorLabel";
			this->errorLabel->Size = System::Drawing::Size(141, 13);
			this->errorLabel->TabIndex = 5;
			this->errorLabel->Text = L"Server connection error";
			this->errorLabel->Visible = false;
			// 
			// ipAddressTextBox
			// 
			this->ipAddressTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ipAddressTextBox->Location = System::Drawing::Point(69, 48);
			this->ipAddressTextBox->Name = L"ipAddressTextBox";
			this->ipAddressTextBox->Size = System::Drawing::Size(302, 24);
			this->ipAddressTextBox->TabIndex = 6;
			// 
			// ipLabel
			// 
			this->ipLabel->AutoSize = true;
			this->ipLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ipLabel->Location = System::Drawing::Point(66, 19);
			this->ipLabel->Name = L"ipLabel";
			this->ipLabel->Size = System::Drawing::Size(205, 18);
			this->ipLabel->TabIndex = 7;
			this->ipLabel->Text = L"Введите IP адрес серверов: ";
			// 
			// buttonWithIPAddress
			// 
			this->buttonWithIPAddress->Location = System::Drawing::Point(162, 78);
			this->buttonWithIPAddress->Name = L"buttonWithIPAddress";
			this->buttonWithIPAddress->Size = System::Drawing::Size(109, 23);
			this->buttonWithIPAddress->TabIndex = 8;
			this->buttonWithIPAddress->Text = L"Поехали!";
			this->buttonWithIPAddress->UseVisualStyleBackColor = true;
			this->buttonWithIPAddress->Click += gcnew System::EventHandler(this, &App::buttonWithIPAddress_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(108, 126);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(149, 17);
			this->radioButton1->TabIndex = 9;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Размер файла подкачки";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Visible = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(108, 156);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(245, 17);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Размер свободных байтов файла подкачки";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Visible = false;
			// 
			// getInfoButton
			// 
			this->getInfoButton->Location = System::Drawing::Point(131, 184);
			this->getInfoButton->Name = L"getInfoButton";
			this->getInfoButton->Size = System::Drawing::Size(181, 23);
			this->getInfoButton->TabIndex = 11;
			this->getInfoButton->Text = L"Получить информацию";
			this->getInfoButton->UseVisualStyleBackColor = true;
			this->getInfoButton->Visible = false;
			this->getInfoButton->Click += gcnew System::EventHandler(this, &App::getInfoButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(105, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(250, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Выберите, какую информацию хотите получить:";
			this->label2->Visible = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(108, 126);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(211, 17);
			this->radioButton3->TabIndex = 13;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Время работы серверного процесса";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(108, 156);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(152, 17);
			this->radioButton4->TabIndex = 14;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Ширина и высота экрана";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Visible = false;
			// 
			// App
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(449, 126);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->getInfoButton);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->buttonWithIPAddress);
			this->Controls->Add(this->ipLabel);
			this->Controls->Add(this->ipAddressTextBox);
			this->Controls->Add(this->errorLabel);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->secondServerButton);
			this->Controls->Add(this->firstServerButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"App";
			this->Text = L"Клиент";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &App::App_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void buttonWithIPAddress_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ip_addr = this->ipAddressTextBox->Text;
	if (String::IsNullOrEmpty(ip_addr))
	{
		this->errorLabel->Visible = true;
		this->errorLabel->Text = L"Поле с адресом не может быть пустым!";
		return;
	}
	IntPtr tmp_ip = Marshal::StringToHGlobalAnsi(ip_addr);
	char* ip_addr_char = static_cast<char*>(tmp_ip.ToPointer());
	String^ err;
	if (connectionToServers(ip_addr_char, err)) {
		this->errorLabel->Visible = true;
		this->errorLabel->Text = err;
	}
	else {
		this->errorLabel->Visible = false;
		this->ipLabel->Visible = false;
		this->ipAddressTextBox->Visible = false;
		this->buttonWithIPAddress->Visible = false;
		this->secondServerButton->Visible = true;
		this->firstServerButton->Visible = true;
		this->buttonWithIPAddress->Visible = false;
		/*this->ClientSize = System::Drawing::Size(459, 252);*/
		/*this->label1->Visible = true;
		this->exitButton->Visible = true;
		this->textBox1->Visible = true;*/
		this->errorLabel->Location = System::Drawing::Point(469, 150);
	}
}
private: System::Void App_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	closeConnection();
}
private: System::Void firstServerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->label1->Visible = false;
	this->radioButton3->Visible = false;
	this->radioButton4->Visible = false;
	this->textBox1->Visible = false;
	this->exitButton->Visible = false;
	this->radioButton1->Visible = true;
	this->radioButton2->Visible = true;
	this->getInfoButton->Visible = true;
	this->label2->Visible = true;
	this->ClientSize = System::Drawing::Size(459, 252);
}
private: void getInfoPretty(String^ for_textbox) {
	this->textBox1->Text = for_textbox;
	this->textBox1->Visible = true;
	this->exitButton->Visible = true;
	this->errorLabel->Visible = false;
	this->ClientSize = System::Drawing::Size(469, 279);
	this->radioButton3->Visible = false;
	this->radioButton4->Visible = false;
	this->getInfoButton->Visible = false;
	this->radioButton1->Visible = false;
	this->radioButton2->Visible = false;
	this->label1->Visible = true;
	this->label2->Visible = false;
}
private: System::Void getInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
	char buf[128];
	if (this->radioButton3->Checked) {
		send(secondClientSocket, "2", 2, 0);
		recv(secondClientSocket, buf, 10, 0);
		int num = std::atoi(buf);
		getInfoPretty(L"Время работы " + Convert::ToString(num) + L" секунд");
	}
	else if (this->radioButton4->Checked) {
		send(secondClientSocket, "1", 2, 0);
		recv(secondClientSocket, buf, 9, 0);
		char* pEnd;
		int num1 = std::strtol(buf, &pEnd, 10);
		int num2 = std::strtol(pEnd, &pEnd, 10);
		getInfoPretty(L"Размер экрана: " + Convert::ToString(num1) + L" " + Convert::ToString(num2));
	}
	else if (this->radioButton1->Checked) {
		send(firstClientSocket, "1", 2, 0);
		recv(firstClientSocket, buf, 10, 0);
		long long num = std::stoll(buf);
		getInfoPretty(L"Размер файла подкачки: " + Convert::ToString(num) + L" байт");
	}
	else if (this->radioButton2->Checked) {
		send(firstClientSocket, "2", 2, 0);
		recv(firstClientSocket, buf, 10, 0);
		long long num = std::stoll(buf);
		getInfoPretty(L"Размер свободного места файла подкачки: " + Convert::ToString(num) + L" байт");
	}
	else {
		this->errorLabel->Location = System::Drawing::Point(85, 210);
		this->errorLabel->Text = L"Выберите хотя бы один вариант";
		this->errorLabel->Visible = true;
	}
}
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	closeConnection();
	exit(EXIT_SUCCESS);
}
private: System::Void secondServerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->radioButton1->Visible = false;
	this->textBox1->Visible = false;
	this->exitButton->Visible = false;
	this->label1->Visible = false;
	this->radioButton2->Visible = false;
	this->radioButton3->Visible = true;
	this->radioButton4->Visible = true;
	this->getInfoButton->Visible = true;
	this->label2->Visible = true;
	this->ClientSize = System::Drawing::Size(459, 252);
}
};
}
