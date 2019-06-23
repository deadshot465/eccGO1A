#include "K14.h"
#include <iostream>
#include <string>

void K14::question1()
{
	std::string str = "ABCDEFGH!!";
	std::cout << "�����Ώۂ̕�����" << str << "\n";
	std::cout << "��������P��������͂��Ă���������";
	std::cin.ignore();
	std::cin.clear();
	char searchChar;
	std::cin >> searchChar;
	auto index = str.find(searchChar);
	if (index != std::string::npos)
	{
		auto subStr = str.substr(index);
		std::cout << "���������ȍ~�̕�����F" << subStr << "\n";
	}
	else
	{
		std::cout << "�����񂪌�����܂���ł����B\n";
	}
}

void swapLargerValue(int& a, int& b)
{
	if (a >= b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
}

void K14::question2()
{
	std::cout << "��ڂ̒l����́�";
	int a = 0;
	std::cin >> a;
	std::cout << "��ڂ̒l����́�";
	int b = 0;
	std::cin >> b;
	swapLargerValue(a, b);
	std::cout << "���ёւ����ʁF" << a << ", " << b << "\n";
}

bool checkRange(float a, float b, float& distance)
{
	distance = sqrtf(a * a + b * b);
	return distance < 10;
}

void K14::question3()
{
	std::cout << "���W���J���}��؂�œ��͂��Ă���������";
	float a = 0;
	float b = 0;
	scanf_s("%f, %f", &a, &b);
	float distance = 0.0f;
	bool result = checkRange(a, b, distance);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(2);
	std::cout << "������" << distance << "�Ȃ̂ŁA�͈�" << (result ? "��" : "�O") << "�ł��B\n";
}

void K14::question4()
{
	std::cout << "�P�ڂ̕��������́�";
	std::cin.clear();
	std::cin.ignore();
	std::string strA;
	std::getline(std::cin, strA, '\n');
	std::cout << "�Q�ڂ̕��������́�";
	std::cin.clear();
	std::string strB;
	std::getline(std::cin, strB, '\n');
	std::cout << (strA == strB ? "����������ł��B" : "�Ⴄ������ł��B");
}
