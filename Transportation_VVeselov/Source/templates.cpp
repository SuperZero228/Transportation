//�������� ����, ��� ���������� ������ ������ ����������� ������� ������ Transportation
#include "Transportation.h"
#include "Transportation.cpp"				//�������� ������� �������� ���� � ����������������, �� ������ � ���� ����� (����� ������ ���������� ������ �� ��������������)

template class Transportation<int>;			//���� ������� ��������� ������� ������ Transportation<int>
template class Transportation<double>;		//���� ������� ��������� ������� ������ Transportation<double>


//������ ������������� ������ Transportation, ������� � ����� ����������� - ��� �������; �� ��� ���� �������� � �������
#include <vector>
#include <iostream>
std::vector<double> get_objective_function_values(int N, int amountB, std::vector<std::vector<double>> vectorOfNeeds, std::vector<double> A, std::vector<std::vector<double>> C)
{
	std::vector<double> objective_function_values;
	for (int k = 0; k < N; k++)
	  {
	  std::vector<double> needs;
	   for (int i = 0; i < amountB; i++)
	    {
	      needs.push_back(vectorOfNeeds[k][i]);
		}

	    Transportation<double> problem(A, needs, C);
	    int L = problem.getL();
		std::cout << std::endl << "result = " << L << std::endl;

	    objective_function_values.push_back(L);
		}

	 return objective_function_values;
}