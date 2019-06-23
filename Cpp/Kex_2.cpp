#include "Kex_2.h"
#include <iostream>
#include "Kex_2_Battle.h"
#include "Kex_2_Enemy.h"

using std::cout;

void Kex_2::Execute()
{
	auto engine = Kex_2::GetEngine<>();
	std::uniform_int_distribution<> generator(0, 2);
	cout << "�`�������n�܂�I\n";
	PlayerEx player;
	player.Hp = PLAYER_INITIAL_HP;
	player.Defense = PLAYER_DEFENSE;
	int continue_game = 1;
	int kills = 0;

	do
	{
		cout << "\n��HP�F" << player.Hp << "\n";
		cout << "���ɐi�݂܂����H�i�P�F���ɐi�ށ@�O�D�A��j��";
		std::cin >> continue_game;
		if (continue_game == 1)
		{
			int lv = generator(engine);
			Enemy enemy = Kex_2_Enemy::CreateEnemy(static_cast<EnemyType>(lv));
			bool result = Kex_2_Battle::AttackEnemy(player, enemy);
			++kills;
			if (!result)
			{
				break;
			}
		}

	} while (continue_game);

	cout << "���Z�~�g�I\n\n";
	cout << "�퓬�񐔁F" << kills << "��@�c��HP�F" << player.Hp << "\n";
}
