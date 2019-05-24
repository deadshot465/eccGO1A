#include "Kex.h"

#include <iostream>
#include <random>

#include "Kex_1sub.h"

using std::cin;
using std::cout;
using std::mt19937;
using std::uniform_int_distribution;

void Kex::Execute()
{
	auto engine = Kex_1sub::GetSeededEngine<>();
	uniform_int_distribution<> generator(0, 4);
	cout << "�`�������n�܂�I\n";

	PlayerEx player;
	bool continue_game = true;
	int kills = 0;

	do
	{
		cout << "\n��HP�F" << player.Hp << "\n";
		cout << "���ɐi�݂܂����H�i�P�F���ɐi�ށ@�O�D�A��j��";
		int choice = 0;
		cin >> choice;
		continue_game = static_cast<bool>(choice);

		if (continue_game)
		{
			int golemLv = generator(engine);
			Kex_1sub::AttackGolem(golemLv, player);
			++kills;
			if (player.Hp == 0)
			{
				break;
			}
		}
	}
	while (continue_game);

	cout << "���Z�~�g�I\n\n";
	cout << "�퓬�񐔁F" << kills << "�@�c��HP�F" << player.Hp;
}