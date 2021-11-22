#pragma once
#include <iostream>
#include <vector>
#include <algorithm> 
#include "libxl.h"
#include <atlconv.h> 


namespace Transportation {

	int mainReadAndCalculate(std::string, int);

	std::wstring s2ws(const std::string& s);

}
