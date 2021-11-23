#include "MainForm.h"
#include <string>
#include "ReadAndCalculate.h"
#include "ResultForm.h"
#include <msclr\marshal_cppstd.h>


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]


void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Transportation::MainForm form;
	Application::Run(% form);
}


System::Void Transportation::MainForm::startButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	fDialog->FileName = fNameBox->Text;

	if (IO::File::Exists(fNameBox->Text)) {
		if (IO::Path::GetExtension(fDialog->FileName) == ".xls" || IO::Path::GetExtension(fDialog->FileName) == ".xlsx") {
			MessageBox::Show("��� � �������!", "�����������");

			std::string sourceFilepath = msclr::interop::marshal_as<std::string>(fDialog->FileName); // �������� �������� �� �����
			std::vector<double> vectorL = FzTransportation::mainReadAndCalculate(sourceFilepath, System::Convert::ToInt32(numberOfSteps->Text));

			this->Hide();
			std::vector<double> real_r = { 0, 0.2, 0.4, 0.6, 0.8, 0.9 };//---------!!!!!!!!!�������!!!!--------------
			Transportation::ResultForm^ rForm = gcnew Transportation::ResultForm(vectorL, real_r);
			rForm->Show();
		}

		else
			MessageBox::Show("�������� ������ �����!\n���������� ����� ������ ���� xls ��� xlsx", "������!");
	}
	else
		MessageBox::Show("���� �� ������!", "������!");

	return System::Void();
}


System::Void Transportation::MainForm::fSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	fDialog->Filter = "*.xls;*.xlsx|*.xls;*.xlsx";

	if (fDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		return;

	String^ filename = fDialog->FileName;

	fNameBox->Text = fDialog->FileName;
	MessageBox::Show("���� ��������!", "�����������");

	return System::Void();
}




