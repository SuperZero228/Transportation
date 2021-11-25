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

	    objective_function_values.push_back(L);
		}

	 return objective_function_values;
}

std::vector<std::pair<double, std::pair<int, int>>> get_optimal_plan(std::vector<double> A, std::vector<double> B, std::vector<std::vector<double>> C) {//���������� �������
	Transportation<double> problem(A, B, C);
	std::vector<std::pair<double, std::pair<int, int>>> basis;

	basis = problem.getBasis();

	/*std::cout << "����������� ���� ���������:" << std::endl;
	for (int i = 0; i < C.size(); i++)
	{
		std::cout << "�� " << i + 1 << "-�� ������ ������������ ���������� ������� ��������� � ";
		for (int j = 0; j < basis.size(); j++)
		{
			if (basis[j].second.first == i && C[basis[j].second.first][basis[j].second.second] != 0)
				std::cout << basis[j].second.second + 1 << "-� ����� ����������� (" << basis[j].first << " ������), ";
		}
		std::cout << std::endl;
	}
	*/

	return basis;
}