#include <iostream>
#include <stdexcept>
#include "K07.h"


K07::K07()
{
}


K07::~K07()
{
}

void showTexts()
{
	std::cout << "Hello World!\n";
	std::cout << "�悤����\n";
	std::cout << "C++����̐��E�ցI\n";
}

void K07::question1()
{
	int choice = 0;
	do
	{
		try {
			std::cout << "���b�Z�[�W��\�����܂����H�i�O�F�I������@�P�F�\������j��";
			std::cin >> choice;
			if (choice == 1)
			{
				showTexts();
			}
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what();
		}
	} while (choice != 0);
}

int max(int value1, int value2, int value3)
{
	int temp = value1 >= value2 ? value1 : value2;
	temp = temp >= value3 ? temp : value3;
	return temp;
}

void K07::question2()
{
	try {
		int numbers[3] = { 0 };
		int count = 0;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << i + 1 << "�ڂ̒l����͂��Ă��������B��";
			std::cin >> numbers[i];
			++count;
		}

		int maxValue = max(numbers[0], numbers[1], numbers[2]);
		std::cout << count << "�̒��ōő�l��" << maxValue << "�ł��B";
	}
	catch (const std::exception & ex)
	{
		std::cerr << ex.what();
	}
}

int GetType(int age)
{
	if (age <= 0)
		return 0;
	else if (age < 3 || age >= 70)
		return 1;
	else if (age >= 3 && age <= 15)
		return 2;
	else if (age >= 60 && age < 70)
		return 3;
	else
		return 4;
}

void K07::question3()
{
	try {
		int age = 0;
		int no = 0;
		std::cout << "�N�����͂��ĉ������B��";
		std::cin >> age;

		no = GetType(age);
		switch (no)
		{
		case 0:
			printf("�s�K�؂Ȓl�����͂���܂����B\n");
			break;
		case 1:
			printf("���ꗿ�������ł��B\n");
			break;
		case 2:
			printf("�q�������Ŕ��z�ł��B\n");
			break;
		case 3:
			printf("�V�j�A�����łP�������ł��B\n");
			break;
		default:
			printf("�ʏ헿���ł��B\n");
			break;
		}
	}
	catch (const std::exception & ex)
	{
		std::cerr << ex.what();
	}
}

void K07::question4()
{
}
