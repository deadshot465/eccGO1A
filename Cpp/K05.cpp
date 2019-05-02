#include <ctime>
#include <iostream>
#include <random>
#include <stdexcept>

#include "Golem.h"
#include "K05.h"

using namespace std;

K05::K05()
{
}


K05::~K05()
{

}

void K05::question1()
{
	float salary = 19.0f;
	int age = 22;

	while (salary < 50.0f)
	{
		salary *= 1.035f;
		++age;
	}

	cout << age << "�΂Ō���" << salary << "���~\n";
}

void K05::question2()
{
	try
	{
		int choice = 0;

		while (choice != 1)
		{
			cout << "�N����`\n";
			cout << "1�D�N�����@2�D����5���c�@3�DZzzz�c\t���́F";
			std::cin >> choice;
		}
		cout << "�悵�A�w�Z�֍s�����I\n";
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

void K05::question3()
{
	try
	{
		int choice = 0;

		while (true)
		{
			cout << "�N����`\n";
			cout << "1�D�N�����@2�D����5���c�@3�DZzzz�c\t���́F";
			std::cin >> choice;
			if (choice == 1)
			{
				cout << "�悵�A�w�Z�֍s�����I\n";
			}
		}
	}
	catch (const std::exception & ex)
	{
		cout << ex.what();
	}
}

void K05::question4()
{
	try
	{
		mt19937 generator(static_cast<mt19937::result_type>(time(nullptr)));
		uniform_int_distribution<> randNumGen(0, 200);
		
		Golem golem{};
		golem.hp = 300 + randNumGen(generator);
		
		uniform_int_distribution<>::param_type newRange(0, 100);
		randNumGen.param(newRange);
		int player_hp = 200 + randNumGen(generator);
		
		std::cout << "�S�[�����@�iHP�F" << golem.hp << "�@�h��́F" << golem.defense << "�j\n";

		while (golem.hp > 0)
		{
			std::cout << "�c��HP�F" << golem.hp << "\n";
			std::cout << "�U����i��I�����Ă��������i1�D�U���@2�D���Z�@3�D���@�j�@��";
			int choice = 0;
			std::cin >> choice;

			int damage = 0;
			
			switch (choice)
			{
			case 1:
			{
				uniform_int_distribution<>::param_type atkRange(0, 40);
				randNumGen.param(atkRange);
				damage = 60 + randNumGen(generator);
				break;
			}
			case 2:
			{
				uniform_int_distribution<>::param_type skillRange(0, 100);
				randNumGen.param(skillRange);
				damage = 30 + randNumGen(generator);
				break;
			}
			case 3:
			{
				uniform_int_distribution<>::param_type magicRange(0, 180);
				randNumGen.param(magicRange);
				damage = 20 + randNumGen(generator);
				break;
			}
			default:
				continue;
			}

			cout << "��b�U���͂�" << damage << "�ł��B\n";
			damage -= golem.defense;

			if (damage <= 0)
			{
				damage = 0;
				cout << "�S�[�����F�u�n�n�n�n�n�A��Ȃ��ȁI�M�l�͎シ����I�v\n";
				cout << "�S�[���������Ȃ����U�����܂����I�U���l�F" << golem.attack << "\n";
				player_hp -= golem.attack;

				if (player_hp <= 0)
				{
					cout << "���Ȃ��̓S�[�����ɕ����܂����I�Q�[���I�[�o�[�I\n";
					return;
				}
				cout << "���Ȃ��̎c��HP�́F" << player_hp << "\n";
			}

			std::cout << "�_���[�W��" << damage << "�ł��B\n";
			golem.hp -= damage;
			if (golem.hp < 0)
			{
				golem.hp = 0;
			}

			std::cout << "�c���HP��" << golem.hp << "�ł��B\n";

			if (golem.hp == 0)
			{
				cout << "�S�[������|���܂����I\n";
			}

		}
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what();
	}
}
