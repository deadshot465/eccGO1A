#include "Kex_1sub.h"

#include <iostream>
#include <boost/iterator/counting_iterator.hpp>

using std::cin;
using std::cout;
using std::mt19937;
using std::uniform_int_distribution;

bool CheckHitOrMiss(int hit)
{
	auto engine = Kex_1sub::GetSeededEngine<>();
	uniform_int_distribution<> generator(0, 99);

	int value = generator(engine);
	return value <= hit - 1;
}

void Kex_1sub::AttackGolem(int lv, PlayerEx& player)
{
	GolemEx golem = {
		lv * 50 + 100,
		lv * 10 + 40,
		GOLEM_ATTACK(lv),
		GOLEM_HIT,
		GOLEM_FLEE
	};

	cout << "�S�[����Lv." << lv + 1 << "�����ꂽ�I\n";
	while (golem.Hp > 0)
	{
		cout << "�S�[���� �c��HP�F" << golem.Hp << "\n";
		cout << "�����I�����Ă��������i�P�D�U���@�Q�D���Z�@�R�D���@�j��";
		int choice = 0;
		cin >> choice;
		int damage = 0;
		bool is_hit = false;

		auto engine = GetSeededEngine<>();
		uniform_int_distribution<> generator(0, 40);

		switch (choice)
		{
		case 1:
			damage = 60 + generator(engine);
			is_hit = CheckHitOrMiss(ATTACK_HIT - golem.Flee);
			break;
		case 2:
			{
			uniform_int_distribution<>::param_type param(0, 100);
			generator.param(param);
			damage = 30 + generator(engine);
			is_hit = CheckHitOrMiss(SKILL_HIT - golem.Flee);
			break;
			}
		case 3:
			{
			uniform_int_distribution<>::param_type param(0, 180);
			generator.param(param);
			damage = 20 + generator(engine);
			is_hit = CheckHitOrMiss(MAGIC_HIT - golem.Flee);
			break;
			}
		default:
			break;
		}

		if (is_hit)
		{
			damage -= golem.Defense;
			if (damage <= 0)
				damage = 0;
			cout << damage << "�̃_���[�W�I\n";
			golem.Hp -= damage;
		}
		else
			cout << "�U�����O�����I\n";

		cout << "�S�[�����̍U���I\n";
		is_hit = CheckHitOrMiss(golem.Hit);
		if (is_hit)
		{
			int injury = golem.Attack - player.Defense;
			cout << injury << "�̃_���[�W�I\n";
			player.Hp -= injury;
			if (player.Hp <= 0)
			{
				player.Hp = 0;
				cout << "���Ȃ��̓S�[�����ɕ����܂����I�Q�[���I�[�o�[�I\n";
				return;
			}
		}
		else
			cout << "�U�����O�����I\n";

		cout << "�v���C���[�c��HP�F" << player.Hp << "\n";

		if (golem.Hp <= 0)
			golem.Hp = 0;
		if (golem.Hp == 0)
			cout << "�S�[����Lv." << lv + 1 << "��|�����I\n";
	}
}