#pragma once
//#using <System.Windows.Forms.DataVisualization.dll>

#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <libxl.h>

using namespace std;
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
		ResultForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
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
	protected:
	private: System::Windows::Forms::Button^ button2;
	//private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button3;



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
			//System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			//System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			//System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			//System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			//this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			//(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 40);
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
			// chart1
			// 
			//chartArea1->Name = L"ChartArea1";
			//this->chart1->ChartAreas->Add(chartArea1);
			//legend1->Name = L"Legend1";
			//this->chart1->Legends->Add(legend1);
			//this->chart1->Location = System::Drawing::Point(418, 104);
			//this->chart1->Name = L"chart1";
			//series1->ChartArea = L"ChartArea1";
			//series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			//series1->Legend = L"Legend1";
			//series1->Name = L"������ ������� ���������� ������������";
			//series2->ChartArea = L"ChartArea1";
			//series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			//series2->Legend = L"Legend1";
			//series2->Name = L"������ ������� ����������� � ���, ��� ���� ���������� �� ��������";
			//this->chart1->Series->Add(series1);
			//this->chart1->Series->Add(series2);
			//this->chart1->Size = System::Drawing::Size(648, 502);
			//this->chart1->TabIndex = 2;
			//this->chart1->Text = L"chart1";
			//this->chart1->Click += gcnew System::EventHandler(this, &ResultForm::chart1_Click);
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
			this->button3->Location = System::Drawing::Point(205, 33);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(207, 40);
			this->button3->TabIndex = 4;
			this->button3->Text = L"������ ������ � ����";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ResultForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1078, 726);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->richTextBox1);
			//this->Controls->Add(this->chart1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"MyForm";
			//(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	//private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {

	//}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //������ ��������� ������
		int const size = 6;
		double reliability_req[size] = { 0, 0.2, 0.4, 0.6, 0.8, 0.9 }; //-------------------------------------
		double reliability_f[size] = { 1, 0.78, 0.57, 0.34, 0.11, 0 }; //-------------------------------------
		double a = 0, b = 100, h = 10, X1, Y1, X2, Y2;

		//��������� ���
		//this->chart1->ChartAreas[0]->AxisX->Title = "������� ������������";
		//this->chart1->ChartAreas[0]->AxisY->Title = "����������";

		//�������� ���� �,�
		//this->chart1->ChartAreas[0]->AxisX->Maximum = 100;
		//this->chart1->ChartAreas[0]->AxisX->Minimum = 0;
		//this->chart1->ChartAreas[0]->AxisY->Maximum = 1;
		//this->chart1->ChartAreas[0]->AxisY->Minimum = 0;

		//������� �����
		//this->chart1->Series[0]->Points->Clear();
		//this->chart1->Series[1]->Points->Clear();

		X1 = 50;
		X2 = 50;

		//for (int i = 0; i < size; i++)
		//{
			//Y1 = reliability_req[i];
			//Y2 = reliability_f[i];
			//this->chart1->Series[0]->Points->AddXY(X1, Y1);
			//this->chart1->Series[1]->Points->AddXY(X2, Y2);
			//X1 += h;
			//X2 += h;
		//}


		//������� ����� ����������� �� �������
		//����� ���������� ���������
		double X_array[size] = { 50, 60, 70, 80, 90, 100 }; //!!!!!!!!!!!!!!!!!!!!!!
		double xy[size];	//��������� x*y
		double xx[size];	//���������� x^2
		int n = size;		//���-�� �����

		double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

		for (int i = 0; i < size; i++)
		{
			xy[i] = X_array[i] * reliability_f[i];
			xx[i] = pow(X_array[i], 2);
		}

		for (int i = 0; i < size; i++)
		{
			sum_x += X_array[i];
			sum_y += reliability_f[i];
			sum_xy += xy[i];
			sum_xx += xx[i];
		}

		double k = 0, b1 = 0;
		k = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - pow(sum_x, 2));
		b1 = (sum_y - k * sum_x) / n;

		//richTextBox1->Text = richTextBox1->Text + "�������� k=" + round(k * 100.0) / 100.0 + "\n";
		//richTextBox1->Text = richTextBox1->Text + "�������� b=" + round(b1 * 100.0) / 100.0 + "\n";
		richTextBox1->Text = richTextBox1->Text + "��������� ��� ������� ���������� ������� ����: y=" + round(k * 100.0) / 100.0 + "x+" + round(b1 * 100.0) / 100.0 + "\n";


		//������ ������� ��������� � ������������ ����� (0,50)(1,100)
		double x1 = 50, x2 = 100, y1 = 0, y2 = 1, k2, b2;
		k2 = (y2 - y1) / (x2 - x1);
		b2 = (x2 * y1 - y2 * x1) / (x2 - x1);

		//richTextBox1->Text = richTextBox1->Text + "�������� k=" + round(k2 * 100.0) / 100.0 + "\n";
		//richTextBox1->Text = richTextBox1->Text + "�������� b=" + round(b2 * 100.0) / 100.0 + "\n";
		richTextBox1->Text = richTextBox1->Text + "��������� ��� ������� ���������� ������������: y=" + round(k2 * 100.0) / 100.0 + "x+ (" + round(b2 * 100.0) / 100.0 + ")" + "\n";


		//���������� x,y
		if ((k / k2) == (b1 / b2))
		{
			richTextBox1->Text = richTextBox1->Text + "����� �����������.\n";
		}
		else
		{
			richTextBox1->Text = richTextBox1->Text + "����� ������������ � ������:\n";
			int x = (b2 - b1) / (k - k2);
			double y = (k * b1 - b2 * k2) / (k - k2);
			richTextBox1->Text = richTextBox1->Text + "x=" + x + "\n";
			richTextBox1->Text = richTextBox1->Text + "y=" + round(y * 100.0) / 100.0 + "\n";

		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //������ ���������
		int const size = 6;																//������ �������
		double min_costs[size] = { 77080, 93208, 109576, 126456, 143576, 152300 };      //����������� �������             
		double reliability_f[size];													    //���������� ������� ����
		double reliability_req[size] = { 0, 0.2, 0.4, 0.6, 0.8, 0.9 };                  //���������� ������������ 
		double min[size];															    //��������� �������

		double C_max = min_costs[0];
		double C_min = min_costs[0];

		for (int i = 1; i < size; i++)
		{
			if (C_max < min_costs[i]) C_max = min_costs[i];
			if (C_min > min_costs[i]) C_min = min_costs[i];
		}

		//richTextBox1->Text = richTextBox1->Text + "max= " + C_max + "\n";
		//richTextBox1->Text = richTextBox1->Text + "min= " + C_min + "\n";

		//--------���������� ������� �������-------------
		for (int i = 0; i < size; i++)
		{
			reliability_f[i] = (C_max - min_costs[i]) / (C_max - C_min);
		}

		richTextBox1->Text = richTextBox1->Text + "���������� ������� ����: \n";
		for (int i = 0; i < size; i++)
		{
			richTextBox1->Text = richTextBox1->Text + "���:" + i + " ���������:" + round(reliability_f[i] * 100.0) / 100.0 + "\n";
		}

		for (int i = 0; i < size; i++)
		{
			if (reliability_req[i] < reliability_f[i])
				min[i] = reliability_req[i];
			else
				min[i] = reliability_f[i];
		}
		//richTextBox1.Text = richTextBox1.Text + "�����������: " + System.Environment.NewLine;
		/*for (int i = 0; i < min_costs.Length; i++)
		{
			richTextBox1.Text = richTextBox1.Text + "���:" + i + " min:" + Math.Round(min[i], 2) + System.Environment.NewLine;
		}*/
		double max = min[0];
		for (int i = 1; i < size; i++)
		{
			if (min[i] > max)
				max = min[i];
		}

		//richTextBox1->Text = richTextBox1->Text + "������������ ����� ����� ����������� ������������ � ����������� ������� ����:" + max + "\n";




	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	}


	};
}
