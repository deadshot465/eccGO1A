#include <ctime>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>
#include "K08.h"
#include "K08_1sub.h"
#include "K08_2sub.h"

using namespace std;

K08::K08()
{
}

K08::~K08()
{
}

void K08::question1()
{
	try {
		auto numbers = vector<int>();
		for (int i = 0; i < 3; ++i)
		{
			cout << i + 1 << "�ڂ̒l����͂��Ă��������B��";
			int num = 0;
			cin >> num;
			numbers.push_back(num);
		}

		cout << "�ǂ���𒲂ׂ܂����H\n";
		cout << "�i�O�F�ő�l�@�P�F�ŏ��l�j��";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << numbers.size() << "�̒��ōő�l��"
				<< K08_1sub::GetMaxValue(numbers[0], numbers[1], numbers[2]) << "�ł��B";
			break;
		case 1:
			cout << numbers.size() << "�̒��ōŏ��l��"
				<< K08_1sub::GetMinValue(numbers[0], numbers[1], numbers[2]) << "�ł��B";
			break;
		default:
			break;
		}
	}
	catch (const exception& ex) {
		cerr << ex.what();
	}
}

void K08::question2()
{
	try
	{
		cout << "�`�������n�܂�I\n";
		mt19937 gen(static_cast<mt19937::result_type>(time(nullptr)));
		uniform_int_distribution<> rand(0, 101);
		int playerHp = 200 + rand(gen);
		bool continueGame = true;

		while (continueGame)
		{
			if (playerHp == 0)
				return;

			cout << "���Ȃ���HP�F" << playerHp << "\n";
			cout << "���ɐi�݂܂����H�i�P�F���ɐi�ށ@�O�D�A��j��";
			int choice = 0;
			cin >> choice;
			continueGame = static_cast<bool>(choice);
			if (continueGame)
			{
				uniform_int_distribution<>::param_type golemParam(0, 5);
				rand.param(golemParam);
				int golemLv = rand(gen);
				K08_2sub::AttackGolem(golemLv, playerHp);
			}
		}
		cout << "�����Z�g�I\n";
	}
	catch (const exception& ex)
	{
		cerr << ex.what();
	}
}

void K08::question3()
{
}

void K08::question4()
{
}
