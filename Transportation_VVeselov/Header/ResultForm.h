#pragma once
//#using <System.Windows.Forms.DataVisualization.dll>

#include "MainForm.h"
#include "ReadAndCalculate.h"
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <libxl.h>

using namespace libxl;

namespace Transportation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class ResultForm : public System::Windows::Forms::Form
	{
	public:
		ResultForm(std::string sourceFilepath, int nSteps)
		{
			InitializeComponent();
			(*numberOfSteps) = nSteps;
			(*filepath2read) = sourceFilepath;
			for (double k = 0; k < (*numberOfSteps); k++)
			{
				(*reliability_req).push_back(k / (*numberOfSteps));   // �������!!!!!! �������� � RAC ������� ��� �������� ��
			}
			(*vecL) = FzTransportation::mainReadAndCalculate(sourceFilepath, (*numberOfSteps));
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~ResultForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	//protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private: std::vector<std::pair<double, std::pair<int, int>>>* resultBasis = new  std::vector<std::pair<double, std::pair<int, int>>>();
	private: std::vector<double>* vecL = new std::vector<double>;
	private: std::vector<double>* reliability_req = new std::vector<double>;                  //���������� ������������ 
	private: std::vector<double>* reliability_f = new std::vector<double>;					//���������� ������� ����
	private: std::string* filepath2read = new std::string();
	private: int* numberOfSteps = new int();
	private: double* result = new double();
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 86);
			this->button1->TabIndex = 0;
			this->button1->Text = L"���������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ResultForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(678, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(170, 40);
			this->button2->TabIndex = 1;
			this->button2->Text = L"��������� ������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ResultForm::button2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 104);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(400, 502);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &ResultForm::richTextBox1_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(205, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(207, 86);
			this->button3->TabIndex = 4;
			this->button3->Text = L"�������� ������ � ����";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ResultForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(27, 622);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(363, 51);
			this->button4->TabIndex = 5;
			this->button4->Text = L"�����";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ResultForm::button4_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(418, 104);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"������ ������� ���������� ������������";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"������ ������� ����������� � ���, ��� ���� ���������� �� ��������";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(648, 502);
			this->chart1->TabIndex = 6;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &ResultForm::chart1_Click);
			// 
			// ResultForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1078, 726);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ResultForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"������� ������������ ������ � ��������� �������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //������ ���������
		button1->Enabled = false;														    

		double C_max = (*vecL)[0];
		double C_min = (*vecL)[0];

		for (int i = 1; i < (*numberOfSteps); i++)
		{
			if (C_max < (*vecL)[i]) C_max = (*vecL)[i];
			if (C_min > (*vecL)[i]) C_min = (*vecL)[i];
		}

		//--------���������� ������� �������-------------

		for (int i = 0; i < (*numberOfSteps); i++)
		{
			this->reliability_f->push_back((C_max - (*vecL)[i]) / (C_max - C_min));
		}

		richTextBox1->Text = richTextBox1->Text + "���������� ������� ����: \n";
		for (int i = 0; i < (*numberOfSteps); i++)
		{
			richTextBox1->Text = richTextBox1->Text + "���:" + i + " ���������:" + round((*reliability_f)[i] * 100.0) / 100.0 + "\n";
		}

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //������ ��������� ������
		button2->Enabled = false;	//������ �� ��������� ������� ������
		
		double a = 0, b = 100, h = 50/((*numberOfSteps) - 1), X1, Y1, X2, Y2;

		//��������� ���
		this->chart1->ChartAreas[0]->AxisX->Title = "������� ������������";
		this->chart1->ChartAreas[0]->AxisY->Title = "����������";

		//�������� ���� �,�
		this->chart1->ChartAreas[0]->AxisX->Maximum = 100;
		this->chart1->ChartAreas[0]->AxisX->Minimum = 0;
		this->chart1->ChartAreas[0]->AxisY->Maximum = 1;
		this->chart1->ChartAreas[0]->AxisY->Minimum = 0;

		//������� �����
		this->chart1->Series[0]->Points->Clear();
		this->chart1->Series[1]->Points->Clear();

		X1 = 50;
		X2 = 50;

		std::vector<double> X_array;

		for (int i = 0; i < (*numberOfSteps); i++)
		{
			X_array.push_back(50 + i * h);
		}

		for (int i = 0; i < (*numberOfSteps); i++)
		{
			Y1 = (*reliability_req)[i];
			Y2 = (*reliability_f)[i];
			this->chart1->Series[0]->Points->AddXY(X1, Y1);
			this->chart1->Series[1]->Points->AddXY(X2, Y2);
			X1 += h;
			X2 += h;
		}

		//������� ����� ����������� �� �������
		//����� ���������� ���������

		std::vector<double> xy;	//��������� x*y
		std::vector<double> xx;	//���������� x^2
		int n = (*numberOfSteps);		//���-�� �����

		double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

		for (int i = 0; i < (*numberOfSteps); i++)
		{
			xy.push_back(X_array[i] * (*reliability_f)[i]);
			xx.push_back(pow(X_array[i], 2));
		}

		for (int i = 0; i < (*numberOfSteps); i++)
		{
			sum_x += X_array[i];
			sum_y += (*reliability_f)[i];
			sum_xy = accumulate(xy.begin(), xy.end(), 0.0);
			sum_xx = accumulate(xx.begin(), xx.end(), 0.0);
		}

		double k = 0, b1 = 0;
		k = ((*numberOfSteps) * sum_xy - sum_x * sum_y) / ((*numberOfSteps) * sum_xx - pow(sum_x, 2));
		b1 = (sum_y - k * sum_x) / (*numberOfSteps);

		//������ ������� ��������� � ������������ ����� (50,0)(100,1)
		double x1 = 50, x2 = 100, y1 = 0, y2 = 1, k2, b2;
		k2 = (y2 - y1) / (x2 - x1);
		b2 = (x2 * y1 - y2 * x1) / (x2 - x1);

		//���������� x,y
		if ((k / k2) == (b1 / b2))
		{
			richTextBox1->Text = richTextBox1->Text + "����� �����������.\n";
		}
		else
		{
			richTextBox1->Text = richTextBox1->Text + "����� ������������ � �����:\n";
			int x = (b2 - b1) / (k - k2);
			double y = (k * b1 - b2 * k2) / (k - k2);
			richTextBox1->Text = richTextBox1->Text + "x=" + x + "\n";
			richTextBox1->Text = richTextBox1->Text + "y=" + round(y * 100.0) / 100.0 + "\n";

			(*result) = FzTransportation::calculateObjectiveFunctionValue((*filepath2read), x);

			(*resultBasis) = FzTransportation::getVVOptimalPlan((*filepath2read), x);
			for (int i = 0; i < (*resultBasis).size(); i++)
			{
				richTextBox1->Text = richTextBox1->Text + "X(" + (*resultBasis)[i].second.first + "," + (*resultBasis)[i].second.second + ")" + "=" + (*resultBasis)[i].first + "\n";
			}

			richTextBox1->Text = richTextBox1->Text + "���������=" + (*result) + "\n";
		}

	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		button3->Enabled = false;
		Book* book = xlCreateBook();
		//-----------������ ������������ �������� ������� ������� ������-----------
		if (book)
		{
			Sheet* sheet = book->addSheet(L"Sheet1");
			if (sheet)
			{
				for (int row = sheet->firstRow(); row < (*vecL).size(); row++)
				{
					for (int col = sheet->firstCol(); col <= sheet->firstCol(); col++)
					{
						double a = (*vecL)[row];
						sheet->writeNum((row + 1), col, a);

					}
				}
				for (int row = sheet->firstRow(); row <= (*reliability_f).size(); row++)
				{
					for (int col = sheet->firstCol(); col <= sheet->firstCol(); col++)
					{
						double a = (*reliability_f)[row - 1]; 
						sheet->writeNum(row, (col + 1), a);

					}
				}
			}
			for (int row = sheet->firstRow(); row <= (*resultBasis).size(); row++)
			{
				for (int col = sheet->firstCol(); col <= sheet->firstCol(); col++)
				{
					double a = (*resultBasis)[row - 1].first;
					sheet->writeNum(row, (col + 2), a);

				}
			}
			for (int row = sheet->firstRow(); row <= 1; row++)
			{
				for (int col = sheet->firstCol(); col <= sheet->firstCol(); col++)
				{
					double a = (*result);
					sheet->writeNum(row, (col + 3), a);

				}
			}
			book->save(L".\\Resource\\result.xls");	
		}
		book->release();

	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();    //�������� �����
		Transportation::MainForm^ mForm = gcnew Transportation::MainForm();
		mForm->Show();
	}

};
}
