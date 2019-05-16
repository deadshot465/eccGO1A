#include <array>
#include <iostream>
#include <stdexcept>
#include "K09.h"

using namespace std;

K09::K09()
= default;


K09::~K09()
= default;

void K09::question1()
{
	try
	{
		int ages[3] = { 0,0,0 };
		for (int i = 0; i < 3; ++i)
		{
			cout << i + 1 << "�l�ڂ̔N�����́�";
			cin >> ages[i];
		}

		for (int i = 0; i < 21; ++i)
		{
			cout << "-";
		}
		cout << "\n";

		float average = 0.0f;
		for (int i = 0; i < 3; ++i)
		{
			cout << i + 1 << "�l�ځF" << ages[i] << "��\n";
			average += static_cast<float>(ages[i]);
		}

		cout << "���ϔN��F" << average / 3.0f << "��\n";
	}
	catch (const exception& ex)
	{
		cerr << ex.what();
	}
}

void K09::question2()
{
	array<int, 5> numbers = { 8, 3, 12, 7, 9 };

	cout << "���X�̔z��F";
	for (int i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << " ";
	}
	cout << "\n";

	cout << "�t���ł̕\���F";
	for (int i = numbers.size() - 1; i >= 0; --i)
	{
		cout << numbers[i] << " ";
	}
}

void K09::question3()
{
	/* int student_scores[3][4] = {
		{52, 71, 61, 47},
		{6, 84, 81, 20},
		{73, 98, 94, 95}
	}; */

	array<array<int, 4>, 3> student_scores = {};
	student_scores[0] = { 52,71,61,47 };
	student_scores[1] = { 6,84, 81, 20 };
	student_scores[2] = { 73, 98, 94, 95 };

	cout << "\t|\t�Ȗ�A\t�Ȗ�B\t�Ȗ�C\t�Ȗ�D\n";
	for (int i = 0; i < 46; ++i)
	{
		cout << "-";
	}
	cout << "\n";

	for (int i = 0; i < student_scores.size(); ++i)
	{
		cout << "�w��" << i + 1 << "\t|\t";
		for (int j = 0; j < student_scores[i].size(); ++j)
		{
			cout << student_scores[i][j] << "\t";
		}
		cout << "\n";
	}
}

void K09::question4()
{
	/* int student_scores[3][4] = {
		{52, 71, 61, 47},
		{6, 84, 81, 20},
		{73, 98, 94, 95}
	}; */

	array<array<int, 4>, 3> student_scores = {};
	student_scores[0] = { 52,71,61,47 };
	student_scores[1] = { 6,84, 81, 20 };
	student_scores[2] = { 73, 98, 94, 95 };

	float average[4] = { 0,0,0,0 };
	int total = 0;

	cout << "\t|\t�Ȗ�A\t�Ȗ�B\t�Ȗ�C\t�Ȗ�D\t|\t���v�_\n";
	for (int i = 0; i < 66; ++i)
	{
		cout << '-';
	}
	cout << '\n';

	for (int i = 0; i < student_scores.size(); ++i)
	{
		cout << "�w��" << i + 1 << "\t|\t";

		for (int j = 0; j < student_scores[i].size(); ++j)
		{
			cout << student_scores[i][j] << "\t";
			total += student_scores[i][j];
			average[j] += static_cast<float>(student_scores[i][j]);

		}
		cout << "|\t" << total;
		total = 0;
		cout << '\n';
		
	}
	cout << "���ϓ_\t|\t";
	for (int i = 0; i < 4; ++i)
	{
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(1);
		cout << average[i] / 3.0f << "\t";
	}
	cout << '|';
}

void K09::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void K09::sort(int* numbers, int total)
{
	for (int i = 0; i < total; ++i)
	{
		for (int j = 0; j < total; ++j)
		{
			if (numbers[j] > numbers[i])
			{
				swap(numbers[i], numbers[j]);
			}
		}
	}
}

void K09::question5()
{
	try
	{
		int numbers[100] = { 0 };
		int count = 0;

		for (int i = 0; i < 100; ++i)
		{
			cout << i + 1 << "���ڂ̓��́F";
			cin >> numbers[i];
			if (numbers[i] < 0)
			{
				break;
			}
			++count;
		}

		sort(numbers, count);
		cout << "----���ёւ���----\n";

		for (int i = 0; i < count; ++i)
		{
			cout << numbers[i] << "\n";
		}
	}
	catch (const exception& ex)
	{
		cerr << ex.what();
	}
}

void K09::execute(int num)
{
	switch (num)
	{
	case 1:
		question1();
		break;
	case 2:
		question2();
		break;
	case 3:
		question3();
		break;
	case 4:
		question4();
		break;
	case 5:
		question5();
		break;
	}
}
