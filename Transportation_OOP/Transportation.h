#pragma once
#include <vector>

template <class T> //для разных типов входных векторов (наши даблы и стандартные инты)
class Transportation 
{
private:
	std::vector<T>arr;	//убрать

public:
	int solve();			//что возвращает? и что передаем? в каком виде данные (таблица из int'ов или нет)?
};