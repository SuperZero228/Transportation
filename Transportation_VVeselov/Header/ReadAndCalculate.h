#pragma once
#include <iostream>
#include <vector>
#include <algorithm> 
#include "libxl.h"
#include <atlconv.h> 


namespace FzTransportation {

	std::vector<double> mainReadAndCalculate(std::string, int);

	std::wstring s2ws(const std::string& s);

	//std::vector<double> get_objective_function_values(int N, int amountB, std::vector<std::vector<double>> vectorOfNeeds, std::vector<double> A, std::vector<std::vector<double>> C);

}
