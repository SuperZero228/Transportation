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
	protected:





	private: System::Windows::Forms::Label^ helpLabel;
	private: System::Windows::Forms::OpenFileDialog^ fDialog;
	private: System::Windows::Forms::Button^ fSearchButton;
	private: System::Windows::Forms::TextBox^ fNameBox;



	protected:

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
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->helpLabel = (gcnew System::Windows::Forms::Label());
			this->fDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fSearchButton = (gcnew System::Windows::Forms::Button());
			this->fNameBox = (gcnew System::Windows::Forms::TextBox());
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
			// helpLabel
			// 
			this->helpLabel->AutoSize = true;
			this->helpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->helpLabel->Location = System::Drawing::Point(9, 9);
			this->helpLabel->Margin = System::Windows::Forms::Padding(0);
			this->helpLabel->Name = L"helpLabel";
			this->helpLabel->Size = System::Drawing::Size(483, 72);
			this->helpLabel->TabIndex = 3;
			this->helpLabel->Text = L"Инструкция\r\n1) Выберете файл с данными транспортной задачи. \r\n2) Нажмите кнопку \""
				L"Запустить\".";

			// 
			// fSearchButton
			//
			this->fSearchButton->Location = System::Drawing::Point(579, 192);
			this->fSearchButton->Name = L"fSearchButton";
			this->fSearchButton->Size = System::Drawing::Size(108, 28);
			this->fSearchButton->TabIndex = 4;
			this->fSearchButton->Text = L"Поиск";
			this->fSearchButton->UseVisualStyleBackColor = true;
			this->fSearchButton->Click += gcnew System::EventHandler(this, &MainForm::fSearchButton_Click);
			// 
			// fNameBox
			// 
			this->fNameBox->Location = System::Drawing::Point(12, 192);
			this->fNameBox->Name = L"fNameBox";
			this->fNameBox->Size = System::Drawing::Size(561, 20);
			this->fNameBox->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(778, 495);
			this->Controls->Add(this->fNameBox);
			this->Controls->Add(this->fSearchButton);
			this->Controls->Add(this->helpLabel);
			this->Controls->Add(this->startButton);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Выбор файла";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void fSearchButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
