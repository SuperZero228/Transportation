#include "ResultForm.h"
#include <Windows.h>
using namespace Transportation; // �������� �������
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ResultForm);
	return 0;
}

