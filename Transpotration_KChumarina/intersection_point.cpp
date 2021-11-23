double intersept(vector<double> reliability_f)
{
	//����� ���������� ���������
	vector<double> X_array = { 50, 60, 70, 80, 90, 100 };
	vector<double> xy;	//��������� x*y
	vector<double> xx;	//���������� x^2
	int n = size;		//���-�� �����

	double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

	for (int i = 0; i < size; i++)
	{
		xy.push_back(X_array[i] * reliability_f[i]);
		xx.push_back(pow(X_array[i], 2));
	}

	for (int i = 0; i < size; i++)
	{
		sum_x += X_array[i];
		sum_y += reliability_f[i];
		sum_xy = accumulate(xy.begin(), xy.end(), 0.0);
		sum_xx = accumulate(xx.begin(), xx.end(), 0.0);
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