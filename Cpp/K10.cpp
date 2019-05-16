#include <array>
#include <iostream>
#include <string>
#include "K10.h"

using namespace std;

K10::K10() = default;


K10::~K10() = default;

void K10::question1()
{
	string inputString;
	cout << "������̓��́�";
	cin >> inputString;

	cout << "���͂��ꂽ������̕������F" << inputString.length();
}

void K10::question2()
{
	string str = "STRINGcopy";

	cout << "�R�s�[������������F" << str << "\n";

	string copyStr{ str };

	cout << "�R�s�[��̕�����F" << copyStr << "\n";

}

void K10::question3()
{

	array<string, 3> str = {
		"abcdef", "GHIJKL", "13579"
	};

	string str_combined;

	cout << "�A���������R�̕�����F\n";
	for (const auto& _str : str)
	{
		str_combined += _str;
	}

	cout << "�A������������F\n" << str_combined;
}

void K10::question4()
{
	string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string inputString = "I AM A STUDENT. I AM GOOD AT GAME PROGRAMMING.";

	cout << "������F" << inputString << "\n\n";

	cout << "�����p�x\n";

	int count = 0;
	int _count = 0;

	int i = 0;

	for (char alphabet : alphabets)
	{
		for (char j : inputString)
		{
			if (alphabet == j)
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
