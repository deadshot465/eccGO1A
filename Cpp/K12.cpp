#include "K12.h"

#include <iostream>
#include <cmath>
#include <random>
#include <string>

#include <cstdio>
#include <ctime>

struct Person
{
	std::string name;
	int birthYear;
	float height;
	float weight;
};

struct Staff
{
	std::string name;
	char gender;
	int age;
};

struct Position
{
	int x;
	int y;
	double distance;
};

void K12::question1()
{
	Person person;
	std::cout << "���O����͂��Ă���������";
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, person.name, '\n');
	std::cout << "���N�i����j����͂��Ă���������";
	std::cin >> person.birthYear;
	std::cout << "�g������͂��Ă���������";
	std::cin >> person.height;
	std::cout << "�̏d����͂��Ă���������";
	std::cin >> person.weight;

	std::cout << "�v���t�@�C���F\n";
	std::cout << "���O�F" << person.name << "\n";
	std::cout << "���N�F" << person.birthYear << "\n";
	std::cout << "�g���F" << person.height << "\n";
	std::cout << "�̏d�F" << person.weight << "\n";
}

void K12::question2()
{
	Staff staffs[3] = {
		{"�_�ؗ��V��", 'M', 23},
		{"�㔒�ΖG��", 'F', 18},
		{"���V�܂���", 'F', 28}
	};

	std::cout << "���O\t\t����\t�N��\n";
	for (int i = 0; i <= 35; ++i)
	{
		std::cout << '-';
	}
	std::cout << "\n";

	for (const auto& staff : staffs)
	{
		std::cout << staff.name << "\t" << staff.gender << "\t" << staff.age << "��\n";
	}
}

double getDistance(const Position& playerPos, const Position& enemyPos)
{
	int diffX = playerPos.x - enemyPos.x;
	int diffY = playerPos.y - enemyPos.y;
	return sqrt(diffX * diffX + diffY * diffY);
}

void K12::question3()
{
	std::mt19937 engine(static_cast<std::mt19937::result_type>(time(nullptr)));
	std::uniform_int_distribution<> rand(0, 101);
	auto getRandomNumber = [&]() { return rand(engine) - 50; };

	Position playerPos = {
		getRandomNumber(), getRandomNumber(), 0.0
	};
	Position enemyPos[5] = {};

	for (auto& enemyPo : enemyPos)
	{
		enemyPo.x = getRandomNumber();
		enemyPo.y = getRandomNumber();
		enemyPo.distance = getDistance(playerPos, enemyPo);
	}

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(2);
	printf("�v���[���[�̍��W�Fx= %.2f\t\ty= %.2f\n\n",
		static_cast<float>(playerPos.x), static_cast<float>(playerPos.y));
	for (int i = 0; i < 5; ++i)
	{
		printf("�G�L�����̍��W0%d�Fx= %5.2f\t\ty= %5.2f\t\t����=%5.2f\n",
			i, static_cast<float>(enemyPos[i].x),
			static_cast<float>(enemyPos[i].y), static_cast<float>(enemyPos[i].distance));
	}
	
}

void swapPos(Position& a, Position& b)
{
	Position temp = a;
	a = b;
	b = temp;
}

void sortPos(Position* positions, int total)
{
	for (int i = 0; i < total; ++i)
	{
		for (int j = 0; j < total; ++j)
		{
			if (positions[j].distance > positions[i].distance)
			{
				swapPos(positions[i], positions[j]);
			}
		}
	}
}

void K12::question4()
{
	std::mt19937 engine(static_cast<std::mt19937::result_type>(time(nullptr)));
	std::uniform_int_distribution<> rand(0, 101);
	auto getRandomNumber = [&]() { return rand(engine) - 50; };

	Position playerPos = {
		getRandomNumber(), getRandomNumber(), 0.0
	};
	Position enemyPos[5] = {};

	for (auto& enemyPo : enemyPos)
	{
		enemyPo.x = getRandomNumber();
		enemyPo.y = getRandomNumber();
		enemyPo.distance = getDistance(playerPos, enemyPo);
	}

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(2);
	printf("�v���[���[�̍��W�Fx= %.2f\t\ty= %.2f\n\n",
		static_cast<float>(playerPos.x), static_cast<float>(playerPos.y));
	for (int i = 0; i < 5; ++i)
	{
		printf("�G�L�����̍��W0%d�Fx= %5.2f\t\ty= %5.2f\t\t����=%5.2f\n",
			i, static_cast<float>(enemyPos[i].x),
			static_cast<float>(enemyPos[i].y), static_cast<float>(enemyPos[i].distance));
	}

	std::cout << "\n���ёւ���\n";
	sortPos(enemyPos, 5);
	for (int i = 0; i < 5; ++i)
	{
		printf("�G�L�����̍��W0%d�Fx= %5.2f\t\ty= %5.2f\t\t����=%5.2f\n",
			i, static_cast<float>(enemyPos[i].x),
			static_cast<float>(enemyPos[i].y), static_cast<float>(enemyPos[i].distance));
	}

}
