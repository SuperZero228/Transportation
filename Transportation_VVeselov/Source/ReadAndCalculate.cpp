#include "ReadAndCalculate.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include "libxl.h"
#include <atlconv.h>
#include "templates.h"

#define ONE_STEP 1

using namespace libxl;

std::vector<double> FzTransportation::mainReadAndCalculate(std::string sourceFilepath, int numberOfSteps)
{
	std::vector<double> A, B;										//обьемы произв-ва и потреб-я в пунктах

	int amountA = 0;                                                //кол-во пунктов производства
	int amountB = 0;
	std::vector<std::vector<double>> C;	                            //кол-во пунктов потребления
	Book* book = xlCreateBook();

	std::wstring wFilepath = s2ws(sourceFilepath);
	const wchar_t* finishedFilepath = wFilepath.c_str();

	A = FzTransportation::readVectorAFromExcell(finishedFilepath, amountA);

	B = FzTransportation::readVectorBFromExcell(finishedFilepath, amountB);

	C = FzTransportation::readVectorCFromExcell(finishedFilepath, amountA, amountB);

	double maxB = *std::max_element(B.begin(), B.end()); 
	std::cout << "максимальная потребность = " << maxB << '\n';
	double bigNum = maxB + 100;

	std::vector<double> beta;
	for (int i = 0; i < amountB; i++)
	{
		beta.push_back(0.5 * B[i]);
		std::cout << "B[" << i << "] = " << B[i] << ";  beta[" << i << "] = " << beta[i] << std::endl;
	}




	std::cout << "Вектора нечетких потребностей " << std::endl;
	std::vector<std::vector<double>> vectorOfNeeds;
	
	std::cout << "введите количество шагов N: ";
	std::cin >> numberOfSteps;
	for (double k = 0; k < numberOfSteps; k++)
	{
		std::vector<double> need;
		for (int i = 0; i < amountB; i++)
		{
			need.push_back(k / numberOfSteps * beta[i] + (B[i] - beta[i]));
		}
		vectorOfNeeds.push_back(need);
	}
	for (double k = 0; k < numberOfSteps; k++)
	{
		for (int i = 0; i < amountB; i++)
		{
			system("echo chlen pause");
			std::cout << vectorOfNeeds[k][i] << "  ";
			//system("pause");
		}
		std::cout << std::endl;
	}
	return get_objective_function_values(numberOfSteps, amountB, vectorOfNeeds, A, C);
}

double FzTransportation::calculateObjectiveFunctionValue(std::string sourceFilepath, int x) {
	std::vector<double> A, B, vL;										//обьемы произв-ва и потреб-я в пунктах
	std::vector<std::vector<double>> C;  	                        //матрица транспортных издержек

	int amountA = 0;                                                //кол-во пунктов производства
	int amountB = 0;												//кол-во пунктов потребления
	double dx = x;

	dx = dx / 100;

	Book* book = xlCreateBook();

	std::wstring wFilepath = FzTransportation::s2ws(sourceFilepath);
	const wchar_t* finishedFilepath = wFilepath.c_str();

	A = FzTransportation::readVectorAFromExcell(finishedFilepath, amountA);

	B = FzTransportation::readVectorBFromExcell(finishedFilepath, amountB);

	C = FzTransportation::readVectorCFromExcell(finishedFilepath, amountA, amountB);


	B = FzTransportation::getVectorBByX(amountB, B, dx);


	std::vector<std::vector<double>> vB;
	vB.push_back(B);

	vL = get_objective_function_values(ONE_STEP, amountB, vB, A, C); // Костыль!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	return vL[0];
}

std::vector<double> FzTransportation::getVectorBByX(int amountB, std::vector<double> B, double x)
{
	std::vector<double> vectorB;

	for (int i = 0; i < amountB; i++)
	{
		vectorB.push_back(B[i] * x);
	}
	return vectorB;
}

std::vector<std::pair<double, std::pair<int, int>>> FzTransportation::getVVOptimalPlan(std::string sourceFilepath, int x) {
	int amountA = 0;
	int amountB = 0;
	std::vector<double> A, B;
	std::vector<std::vector<double>> C;
	std::vector<std::pair<double, std::pair<int, int>>> basis;
	double dx = x;

	dx = dx / 100;

	std::wstring wFilepath = FzTransportation::s2ws(sourceFilepath);
	const wchar_t* finishedFilepath = wFilepath.c_str();


	A = FzTransportation::readVectorAFromExcell(finishedFilepath, amountA);

	B = FzTransportation::readVectorBFromExcell(finishedFilepath, amountB);

	C = FzTransportation::readVectorCFromExcell(finishedFilepath, amountA, amountB);

	B = FzTransportation::getVectorBByX(amountB, B, dx);
	
	return get_optimal_plan(A, B, C);;
}

std::wstring FzTransportation::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	std::wstring r(len, L'\0');
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
	return r;
}

std::vector<double> FzTransportation::readVectorAFromExcell(const wchar_t* finishedFilepath, int &amountA) {

	std::vector<double> A;
	Book* book = xlCreateBook();

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
	book->release();

	return A;
}

std::vector<double> FzTransportation::readVectorBFromExcell(const wchar_t* finishedFilepath, int& amountB) {

	std::vector<double> B;
	Book* book = xlCreateBook();

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
	book->release();

	return B;
}

std::vector<std::vector<double>> FzTransportation::readVectorCFromExcell(const wchar_t* finishedFilepath, int &amountA, int &amountB) {

	Book* book = xlCreateBook();

	std::vector<std::vector<double>> C(amountA, std::vector <double>(amountB));

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
					C[row - 5][col] = d;
				}
			}
		}
	}
	book->release();	

	return C;
}

