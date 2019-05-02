#include <ctime>
#include <iostream>
#include <random>
#include <stdexcept>

#include "K03.h"



K03::K03()
{
}


K03::~K03()
{
}

void K03::question1()
{
	try
	{
		std::cout << "�N�����͂��Ă��������B��";
		int age = 0;
		std::cin >> age;
		
		if (age < 20)
		{
			std::cout << "�����N�Ȃ̂ōw���ł��܂���B\n";
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}

void K03::question2()
{
	try
	{
		std::cout << "�g������͂��Ă��������B��";
		float height = 0.0f;
		std::cin >> height;
		height /= 100.0f;
		std::cout << "�̏d����͂��Ă��������B��";
		float weight = 0.0f;
		std::cin >> weight;
		
		float standard = height * height * 22.0f;
		std::cout << "���Ȃ��̕W���̏d��" << standard << "�ł��B\n";

		if (weight > standard && (weight - standard) / standard * 100.0f > 14.0f)
		{
			std::cout << "����C���ł��B\n";
		}
		else if (weight < standard && (weight - standard) / standard * 100.0f < -14.0f)
		{
			std::cout << "�����C���ł��B\n";
		}
		else
		{
			std::cout << "���ʂł��ˁB\n";
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
	
}

void K03::question3()
{
	try
	{
		std::mt19937 generator(static_cast<std::mt19937::result_type>(std::time(nullptr)));
		std::uniform_int_distribution<> randNumGen(0, 99);

		int randNum = randNumGen(generator);

		std::cout << "�O����X�X�͈̔͂̐��l�����肳��܂����B\n";
		std::cout << "���߂�ꂽ���l��\�z���A���̐��l�����傫�Ȓl����͂��Ă���������";
		int guess = 0;
		std::cin >> guess;
		
		std::cout << "���߂�ꂽ���l��" << randNum << "�ł��B\n";
		std::cout << ((guess > randNum) ? "�����ł��B\n" : "�s�����ł��B\n");
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what();
	}
}

void K03::question4()
{
	try
	{
		std::mt19937 generator(static_cast<std::mt19937::result_type>(std::time(nullptr)));
		std::uniform_int_distribution<> randNumGen(0, 99);

		int randNum = randNumGen(generator);

		std::cout << "�O����X�X�͈̔͂̐��l�����肳��܂����B\n";
		std::cout << "���߂�ꂽ���l��\�z���A���̐��l�����傫�Ȓl����͂��Ă���������";
		int guess = 0;
		std::cin >> guess;

		std::cout << "���߂�ꂽ���l��" << randNum << "�ł��B\n";
		
		if (guess < 0 || guess > 100)
		{
			std::cout << "�����ł��I";
		}
		else if (guess > randNum && guess - randNum <= 10)
		{
			std::cout << "�吳���ł��I";
		}
		else if (guess < randNum && guess - randNum >= -10)
		{
			std::cout << "�ɂ����I";
		}
		else if (guess == randNum)
		{
			std::cout << "�������I";
		}
		else
		{
			std::cout << ((guess > randNum) ? "�����ł��B\n" : "�s�����ł��B\n");
		}
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what();
	}
}
