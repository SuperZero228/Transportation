#pragma once
#include <vector>

std::vector<double> get_objective_function_values(int N, int amountB, std::vector<std::vector<double>> vectorOfNeeds, std::vector<double> A, std::vector<std::vector<double>> C);

std::vector<std::pair<double, std::pair<int, int>>> get_optimal_plan(std::vector<double> A, std::vector<double> B, std::vector<std::vector<double>> C); //переделать функцию
