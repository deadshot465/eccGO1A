#include <iostream>
#include <stdexcept>
#include "Golem.h"
#include "K08_2sub.h"

K08_2sub::K08_2sub()
{
}

K08_2sub::~K08_2sub()
{
}

enum AttackMethod {
	Attack = 65,
	Skill = 99,
	Magic = 133
};

void K08_2sub::AttackGolem(int lv, int& playerHp)
{
	try {
		Golem golem = Golem(lv * 50 + 100, lv * 10 + 40, lv * 10 + 30);

		std::cout << "�S�[����Lv." << lv + 1 << "�����ꂽ�I\n";
		while (golem.hp > 0)
		{
			std::cout << "\n�c��HP�F" << golem.hp << "\n";
			std::cout << "�����I�����Ă��������i�P�D�U���@�Q�D���Z�@�R�D���@�j��";
			int choice = 0;
			std::cin >> choice;
			int damage = 0;

			switch (choice)
			{
			case 1:
				damage = static_cast<int>(Attack);
				break;
			case 2:
				damage = static_cast<int>(Skill);
				break;
			case 3:
				damage = static_cast<int>(Magic);
				break;
			default:
				break;
			}
			damage -= golem.defense;

			if (damage <= 0) {
				damage = 0;
				std::cout << "�S�[�����F�u�n�n�n�n�n�A��Ȃ��ȁI�M�l�͎シ����I�v\n";
				std::cout << "�S�[���������Ȃ����U�����܂����I�U���l�F" << golem.attack << "\n";
				playerHp -= golem.attack;
				if (playerHp <= 0)
				{
					playerHp = 0;
					std::cout << "���Ȃ��̓S�[�����ɕ����܂����I�Q�[���I�[�o�[�I\n";
					return;
				}
				std::cout << "���Ȃ��̎c��HP�́F" << playerHp << "\n";
			}
			std::cout << "�_���[�W��" << damage << "�ł��B\n";
			golem.hp -= damage;

			if (golem.hp <= 0)
				golem.hp = 0;
			if (golem.hp == 0)
				std::cout << "�S�[����Lv." << lv + 1 << "��|�����I\n";
		}
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}
}
