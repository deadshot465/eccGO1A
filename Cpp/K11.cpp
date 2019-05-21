#include "K11.h"
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

constexpr int MAX_PEOPLE = 3;

void K11::question1()
{
	int age = 0;
	float average = 0;

	for (int i = 0; i < MAX_PEOPLE; ++i)
	{
		cout << i + 1 << "�l�ڂ̔N�����͂��ĉ������F";
		cin >> age;
		average += static_cast<float>(age);
	}

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(1);
	cout << MAX_PEOPLE << "�l�̕��ϔN���" << average / static_cast<float>(MAX_PEOPLE) << "�ł��B";
}

void K11::question2()
{
	cout << "1�ڂ̕��������͂��ĉ������B��";
	string str1;
	cin.clear();
	cin.ignore();
	getline(cin, str1, '\n');
	

	cout << "2�ڂ̕��������͂��ĉ������B��";
	string str2;
	cin.clear();
	getline(cin, str2, '\n');
	
	
	str1 += str2;
	cout << str1 << "�̕�������" << str1.length() << "�ł��B";
}

void K11::question3()
{
	char chr;
	cout << "��������͂��ĉ������B��";
	cin >> chr;
	bool applied = false;

	if (isdigit(chr))
	{
		cout << "���̕����͐����ł��B\n";
		applied = true;
	}

	if (isupper(chr))
	{
		cout << "���̕����͉p�啶���ł��B\n";
		applied = true;
	}

	if (islower(chr))
	{
		cout << "���̕����͉p�������ł��B\n";
		applied = true;
	}


	if (isxdigit(chr))
	{
		cout << "���̕�����16�i���Ƃ��Ďg���镶���ł��B\n";
		applied = true;
	}


	if (ispunct(chr))
	{
		cout << "���̕����͋�؂蕶���ł��B\n";
		applied = true;
	}

	if (!applied)
	{
		cout << "���̕����͂悭�킩��Ȃ������ł��B";
	}
}

void K11::question4()
{
	string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string inputString = "I am a STUDENT. I am good at GAME PROGRAMMING.";

	cout << "������F" << inputString << "\n\n";

	cout << "�����p�x\n";

	int count = 0;
	int _count = 0;

	int i = 0;

	for (char alphabet : alphabets)
	{
		for (char j : inputString)
		{
			if (alphabet == std::toupper(j))
			{
				++_count;
			}
		}

		cout << alphabet << ": " << _count << "\t";
		_count = 0;
		++count;

		if (count % 4 == 0)
		{
			printf("\n");
		}
	}
}
