#include <ctime>
#include <iostream>
#include <random>
#include <stdexcept>

#include "K04.h"

using namespace std;

K04::K04()
{
}


K04::~K04()
{
}

void K04::question1()
{
	try
	{
		cout << "�N�����͂��Ă��������B��";
		int age = 0;
		cin >> age;

		if (age < 3 || age >= 70)
		{
			cout << "���ꗿ�������ł��B\n";
		}
		else
		{
			cout << "�ʏ헿���ł��B\n";
		}

	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

void K04::question2()
{
	try
	{
		cout << "���ʂ�I�����Ă��������B�i�O�F�j���@�P�F�����j��";
		int gender = 0;
		cin >> gender;

		switch (gender)
		{
		case 0:
			cout << "����A�i�D�ǂ��ł��ˁB\n";
			break;
		case 1:
			cout << "����A���f������݂����ł��ˁB\n";
			break;
		default:
			cout << "����ȑI�����͂���܂���B\n";
			break;
		}

	}
	catch (const std::exception & ex)
	{
		cout << ex.what();
	}
}

void K04::question3()
{
	try
	{
		cout << "�N�����͂��Ă��������B��";
		int age = 0;
		cin >> age;

		if (age < 3 || age >= 70)
		{
			cout << "���ꗿ�������ł��B\n";
		}
		else if (age >= 3 && age <= 15)
		{
			cout << "�q�������Ŕ��z�ł��B\n";
		}
		else if (age >= 60 && age < 70)
		{
			cout << "�V�j�A�����ňꊄ�����ł��B\n";
		}
		else
		{
			cout << "�ʏ헿���ł��B\n";
		}

	}
	catch (const std::exception & ex)
	{
		cout << ex.what();
	}
}

void K04::question4()
{
	try
	{
		cout << "���������݂����v���O����������\n";
		cout << "���݂����������܂����@�i�͂��F�P�@�������F�O�j�@��";
		int choice = 0;
		cin >> choice;

		if (choice >= 1)
		{
			mt19937 generator(static_cast<mt19937::result_type>(time(nullptr)));
			uniform_int_distribution<> randNumGen(0, 4);
			int oracle = randNumGen(generator);

			switch (oracle)
			{
			case 0:
				cout << "��g�@�Ƃ��Ă��������Ƃ����肻���I�I\n";
				break;
			case 1:
				cout << "���g�@�����Ƃ������Ƃ���񂶂�Ȃ�����\n";
				break;
			case 2:
				cout << "���g�@�������炢�͂������Ƃ��邩����\n";
				break;
			case 3:
				cout << "���@�����͂��ƂȂ����Ă�����������������\n";
				break;
			case 4:
				cout << "�勥�@���ꂶ���΂��Ȃ��H�����ƂɋA����������������\n";
				break;
			default:
				break;
			}
		}

	}
	catch (const std::exception & ex)
	{
		cout << ex.what();
	}
}
