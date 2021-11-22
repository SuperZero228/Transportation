//�������� ����, ��� ���������� ������ ������ ����������� ������� ������ Transportation
#include "Transportation.h"
#include "Transportation.cpp"				//�������� ������� �������� ���� � ����������������, �� ������ � ���� ����� (����� ������ ���������� ������ �� ��������������)

template class Transportation<int>;			//���� ������� ��������� ������� ������ Transportation<int>
template class Transportation<double>;		//���� ������� ��������� ������� ������ Transportation<double>



//������ ������������� ������ Transportation, ������� � ����� ����������� - ��� �������; �� ��� ���� �������� � �������
#include <vector>
#include <iostream>
int main() 
{
	setlocale(LC_ALL, "Russian");
	std::vector<int> A = { 94,85,36,11 };
	std::vector<int> B = { 23,17,15,19,40,14 };
	std::vector<std::vector<int>> C = { {6,5,6,4,2,3},{8,7,5,3,3,2}, {8,9,8,7,2,6}, {8,7,3,5,4,1} };
	int L;

	Transportation<int> problem(A, B, C);
	L = problem.getL();
	std::cout << std::endl << "result = " << L << std::endl;		//441
	system("pause");
	return 0;
}