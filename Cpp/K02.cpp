#include "Golem.h"
#include "K02.h"



K02::K02()
{
}


K02::~K02()
{
}
#include <iostream>


void K02::question1()
{
	int seisuu = 3;
	float jissuu = 2.6f;
	char moji = 'A';

	std::cout << "�ϐ�seisuu�̒l��" << seisuu << "\n";
	std::cout << "�ϐ�jissuu�̒l��" << jissuu << "\n";
	std::cout << "�ϐ�moji�̒l��" << moji << "\n";
}

void K02::question2()
{
	try
	{
		std::cout << "��ڂ̐����́H";
		int number1 = 0;
		std::cin >> number1;
		std::cout << "��ڂ̐����́H";
		int number2 = 0;
		std::cin >> number2;

		std::cout << number1 << "��" << number2 << "="
			<< number1 / number2 << "..." << number1 % number2;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}

}

void K02::question3()
{
	try
	{
		std::cout << "��ڂ̏��i�̒l�i�́H";
		int priceA = 0;
		std::cin >> priceA;
		std::cout << "���́H";
		int amountA = 0;
		std::cin >> amountA;
		std::cout << "��ڂ̏��i�̒l�i�́H";
		int priceB = 0;
		std::cin >> priceB;
		std::cout << "���́H";
		int amountB = 0;
		std::cin >> amountB;

		float total = (priceA * amountA + priceB * amountB) * 1.08f;
		std::cout << "���x�����͐ō��݁�" << total << "�ł��B";
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}

void K02::question4()
{
	try
	{
		Golem golem{};
		std::cout << "�S�[�����@�iHP�F" << golem.hp << "�@�h��́F" << golem.defense << "�j\n";
		std::cout << "HP�F" << golem.hp << "\n";
		std::cout << "����̍U���̒l����͂��Ă���������";
		int damage = 0;
		std::cin >> damage;

		damage = damage - golem.defense > 0 ? damage - golem.defense : 0;

		std::cout << "�_���[�W��" << damage << "�ł��B\n";
		golem.hp -= damage;
		std::cout << "�c���HP��" << golem.hp << "�ł��B\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}
