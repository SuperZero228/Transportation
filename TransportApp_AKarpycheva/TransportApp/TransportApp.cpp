#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include "libxl.h"
#include <atlconv.h> 

using namespace libxl;

std::wstring s2ws(const std::string& s); 

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector<double> A, B;										//обьемы произв-ва и потреб-я в пунктах

	int amountA = 0;                                                //кол-во пунктов производства
	int amountB = 0;												//кол-во пунктов потребления
	Book* book = xlCreateBook();

	std::string sourceFilepath("C:\\Users\\Ангелина\\Desktop\\Нечеткая логика\\example.xls");
	std::wstring wFilepath = s2ws(sourceFilepath);
	const wchar_t* finishedFilepath = wFilepath.c_str();

	if (book->load(finishedFilepath))
	{
		Sheet* sheet = book->getSheet(0);
		if (sheet)
		{
			std::cout << "объемы производства " << std::endl;
			for (int row = sheet->firstRow(); row <= sheet->firstRow(); row++)
			{
				for (int col = sheet->firstCol(); col < sheet->lastCol(); col++)
				{
					double d = sheet->readNum(row, col);
					if (d == 0) {
						break;
					}
					amountA++;
					A.push_back(d);
				}
			}
		}
	}
	for (int i = 0; i < amountA; i++)
	{
		std::cout << A[i] << "  ";
	}
	std::cout << std::endl << "amountA = " << amountA << std::endl;

	if (book->load(finishedFilepath))
	{
		Sheet* sheet = book->getSheet(0);
		if (sheet)
		{
			std::cout << "объемы потребления " << std::endl;
			for (int row = 3; row <= 3; row++)
			{
				for (int col = sheet->firstCol(); col < sheet->lastCol(); col++)
				{
					amountB = sheet->lastCol();
					double d = sheet->readNum(row, col);
					B.push_back(d);
				}
			}
		}
	}	
	for (int i = 0; i < amountB; i++)
	{
		std::cout << B[i] << "  ";
	}
	std::cout << std::endl << "amountB = " << amountB << std::endl;

	std::vector<std::vector<double>> C(amountA, std::vector <double>(amountB));		//матрица транспортных издержек

	if (book->load(finishedFilepath))
	{
		Sheet* sheet = book->getSheet(0);
		if (sheet)
		{
			std::cout << "матрица издержек " << std::endl;	
			for (int row = 5; row < sheet->lastRow(); row++)
			{
				for (int col = sheet->firstCol(); col < sheet->lastCol(); col++)
				{
					double d = sheet->readNum(row, col);
					C[row-5][col] = d;
				}				
			}
		}
	}
	book->release();

	for (int i = 0; i < amountA; i++)
	{
		for (int j = 0; j < amountB; j++)
		{
			std::cout << C[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	double maxB = *std::max_element(B.begin(), B.end()); 
	std::cout << "максимальная потребность = " << maxB << '\n';
	double bigNum = maxB + 100;

	std::vector<double> beta;
	for (int i = 0; i < amountB; i++)
	{
		beta.push_back(0.5 * B[i]);
		std::cout << "B[" << i << "] = " << B[i] << ";  beta[" << i << "] = " << beta[i] << std::endl;
	}


	std::vector<double> fuzzyValues;
	for (int i = 0; i < amountB; i++)
	{
		fuzzyValues.push_back(B[i] - beta[i]);
		fuzzyValues.push_back(B[i]);
		fuzzyValues.push_back(bigNum);
	}

	std::cout << "нечеткие величины (треугольные числа)" << std::endl;
	for (int i = 0; i < (3 * amountB); i++)
	{
		std::cout << fuzzyValues[i] << ";  ";
		if ((i + 1) % 3 == 0)
		{
			std::cout << "\n";
		}
	}


	std::cout << "Вектора нечетких потребностей " << std::endl;
	double N;
	std::vector<std::vector<double>> vectorOfNeeds;
	
	std::cout << "введите количество шагов N: ";
	std::cin >> N;
	for (double k = 0; k < N; k++)
	{
		std::vector<double> need;
		for (int i = 0; i < amountB; i++)
		{
			need.push_back(k / N * beta[i] + (B[i] - beta[i]));
		}
		vectorOfNeeds.push_back(need);
	}

	for (double k = 0; k < N; k++)
	{
		for (int i = 0; i < amountB; i++)
		{
			std::cout << vectorOfNeeds[k][i] << "  ";
		}
		std::cout << std::endl;
	}
	system("pause");
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	std::wstring r(len, L'\0');
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
	return r;
}

