#pragma once

namespace Transportation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::Label^ helpLabel1;
	protected:






	private: System::Windows::Forms::OpenFileDialog^ fDialog;
	private: System::Windows::Forms::Button^ fSearchButton;
	private: System::Windows::Forms::TextBox^ fNameBox;
	private: System::Windows::Forms::Label^ helpLabel2;
	private: System::Windows::Forms::TextBox^ numberOfSteps;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->helpLabel1 = (gcnew System::Windows::Forms::Label());
			this->fDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fSearchButton = (gcnew System::Windows::Forms::Button());
			this->fNameBox = (gcnew System::Windows::Forms::TextBox());
			this->helpLabel2 = (gcnew System::Windows::Forms::Label());
			this->numberOfSteps = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(612, 406);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 30);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Запуск";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MainForm::startButton_Click);
			// 
			// helpLabel1
			// 
			this->helpLabel1->AutoSize = true;
			this->helpLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->helpLabel1->Location = System::Drawing::Point(9, 9);
			this->helpLabel1->Margin = System::Windows::Forms::Padding(0);
			this->helpLabel1->Name = L"helpLabel1";
			this->helpLabel1->Size = System::Drawing::Size(483, 72);
			this->helpLabel1->TabIndex = 3;
			this->helpLabel1->Text = L"Инструкция\r\n1) Выберете файл с данными транспортной задачи. \r\n2) Нажмите кнопку \""
				L"Запуск\".";
			this->helpLabel1->Click += gcnew System::EventHandler(this, &MainForm::helpLabel_Click);
			// 
			// fSearchButton
			// 
			this->fSearchButton->Location = System::Drawing::Point(579, 106);
			this->fSearchButton->Name = L"fSearchButton";
			this->fSearchButton->Size = System::Drawing::Size(108, 20);
			this->fSearchButton->TabIndex = 4;
			this->fSearchButton->Text = L"Поиск";
			this->fSearchButton->UseVisualStyleBackColor = true;
			this->fSearchButton->Click += gcnew System::EventHandler(this, &MainForm::fSearchButton_Click);
			// 
			// fNameBox
			// 
			this->fNameBox->Location = System::Drawing::Point(12, 106);
			this->fNameBox->Name = L"fNameBox";
			this->fNameBox->Size = System::Drawing::Size(561, 20);
			this->fNameBox->TabIndex = 5;
			// 
			// helpLabel2
			// 
			this->helpLabel2->AutoSize = true;
			this->helpLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->helpLabel2->Location = System::Drawing::Point(12, 138);
			this->helpLabel2->Name = L"helpLabel2";
			this->helpLabel2->Size = System::Drawing::Size(283, 24);
			this->helpLabel2->TabIndex = 3;
			this->helpLabel2->Text = L"1) Введите количество шагов.";
			// 
			// numberOfSteps
			// 
			this->numberOfSteps->Location = System::Drawing::Point(579, 143);
			this->numberOfSteps->Name = L"numberOfSteps";
			this->numberOfSteps->Size = System::Drawing::Size(106, 20);
			this->numberOfSteps->TabIndex = 6;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(778, 495);
			this->Controls->Add(this->numberOfSteps);
			this->Controls->Add(this->helpLabel2);
			this->Controls->Add(this->fNameBox);
			this->Controls->Add(this->fSearchButton);
			this->Controls->Add(this->helpLabel1);
			this->Controls->Add(this->startButton);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Выбор файла";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void fSearchButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void helpLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
