#include "K13.h"
#include <array>
#include <iostream>
#include <random>


void K13::question1()
{
	int a = 10;
	int* p = &a;
	std::cout << "a�̒l�F" << a << "\n";
	std::cout << "a�̃A�h���X�F" << &a << "\n";
	std::cout << "p�̒l�F" << p << "\n";
	std::cout << "p���Q�Ƃ���ϐ��̒l�F" << *p << "\n";
	std::cout << "p�̃A�h���X�F" << &p << "\n";
}

void K13::question2()
{
	int arr[10] = { 0 };
	int* ptr = arr;
	for (int i = 0; i < 10; ++i)
	{
		*ptr = i;
		std::cout << "�z��[" << i << "] = " << *ptr << "\n";
		++ptr;
	}
}

void K13::question3()
{
	int data[] = { 2, 8, 10, 3, 1, 9, 4, 3, 6, -1 };
	int total = 0;
	int* ptr = data;
	std::cout << "�f�[�^�F";
	while (*ptr >= 0)
	{
		std::cout << *ptr << "\t";
		total += *ptr;
		++ptr;
	}
	std::cout << "\n���v��" << total << "�ł��B";
}

template <typename T = std::mt19937, std::size_t U = T::state_size>
auto GetEngine() -> typename std::enable_if<!!U, T>::type
{
	typename T::result_type data[U];
	std::random_device rd;
	std::generate(std::begin(data), std::end(data), std::ref(rd));
	std::seed_seq seeds(std::begin(data), std::end(data));
	T engine(seeds);
	return engine;
}

void K13::question4()
{
	auto engine = GetEngine();
	std::uniform_int_distribution<> generator(0, 100);
	auto data = std::array<int, 10>();
	std::generate(std::begin(data), std::end(data), [&]()
		{
			return generator(engine);
		});

	auto iter = data.begin();
	int sum = 0;
	std::cout << "�f�[�^�F";
	while (iter != data.end())
	{
		std::cout << *iter << "\t";
		sum += *iter;
		++iter;
	}

	std::cout << "\n���v��" << sum << "�ł��B";
}
