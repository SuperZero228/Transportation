#pragma once
#include <vector>

template <class T> //��� ������ ����� ������� �������� (���� ����� � ����������� ����)
class Transportation 
{
private:
	std::vector<T>arr;	//������

public:
	int solve();			//��� ����������? � ��� ��������? � ����� ���� ������ (������� �� int'�� ��� ���)?
};