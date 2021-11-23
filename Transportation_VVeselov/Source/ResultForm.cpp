#include "ResultForm.h"
#include <Windows.h>
using namespace Transportation; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	std::vector<double> vecL = { 1,2,3,4,5,6,7 }; //------------------!!!!!!!!!!!!КОСТЫЛЬ!!!!!!!!!!!------------
	std::vector<double> reliability_req = { 0, 0.2, 0.4, 0.6, 0.8, 0.9 };
	Application::Run(gcnew ResultForm(vecL, reliability_req));
	return 0;
}

