#pragma once
#include <iostream>
#include <vector>
#include <algorithm> 
#include "libxl.h"
#include <atlconv.h> 


namespace FzTransportation {

	std::vector<double> mainReadAndCalculate(std::string, int);

	std::wstring s2ws(const std::string& s);

	double calculateObjectiveFunctionValue(std::string sourceFilepath, int x);

	std::vector<double> getVectorBByX(int amountB, std::vector<double> B, double x);

	std::vector<double> readVectorAFromExcell(const wchar_t* finishedFilepath, int& amountA);

	std::vector<double> readVectorBFromExcell(const wchar_t* finishedFilepath, int& amountB);

	std::vector<std::vector<double>> readVectorCFromExcell(const wchar_t* finishedFilepath, int& amountA, int& amountB);

	std::vector<std::pair<double, std::pair<int, int>>>  getVVOptimalPlan(std::string sourceFilepath, int x); //Костыль
}
