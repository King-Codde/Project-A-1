#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include"Class.h"

void info(const int n, int& lvl_number, int lvl[10], int lvl_exp[10], int& exp, int& hp, int& dmg, int& money, std::string weapon_name, std::string armor_name, int& goddamn) {
    setlocale(LC_ALL, "rus");
    std::cout << "��� ������� " << lvl[lvl_number] << "." << std::endl;
    if (lvl_number + 1 != n) {
        std::cout << "�� ������ ������ �������� " << lvl_exp[lvl_number] - exp << " �����." << std::endl;
    }
    else {
        std::cout << "�� ������ ������ �������� 0 �����." << std::endl;
    }
    std::cout << "���� ���������� ��������� " << goddamn / 10 << ". " << "���� �������� ����� ���������� �� " << goddamn << "." << std::endl;
    std::cout << "���� �������� " << hp << "." << std::endl;
    std::cout << "��� ���� " << dmg << "." << std::endl;
    std::cout << "���������� ����� " << money << "." << std::endl;
    std::cout << "���� ������ " << weapon_name << "." << std::endl;
    std::cout << "���� ����� " << armor_name << "." << std::endl << std::endl;
}
void battle(int& enemy, int& hp, int& enemy_hp, int& dmg, int& enemy_dmg, int& money, int& enemy_money, int& lvl_number, const int n, int& enemy_exp, int& exp, int lvl_exp[], int lvl_hp[], int& hp_item, int& goddamn) {
    setlocale(LC_ALL, "rus");
    int hit;
    int lvlexp = lvl_exp[lvl_number];
    int lvlhp = lvl_hp[lvl_number];
    int chance, head_chance = 35, body_chance = 80, arm_chance = 42;
    if (enemy != 0) {
        while (hp > 0) {
            std::cout << "���� ���������� ����� " << hp << "." << std::endl;
            std::cout << "���������� ������ ���������� " << enemy_hp << "." << std::endl;
            std::cout << "�������� ���� ������� ����\n1) ������\n2) ����\n3) ����" << std::endl;
            std::cin >> hit;
            switch (hit)
            {
            case 1:
                chance = rand() % 100;
                if (chance < head_chance) {
                    std::cout << "�� ������� ���� � ������" << std::endl;
                    std::cout << "����� ������� ���� �� " << dmg << " �����." << std::endl;
                    enemy_hp -= dmg;
                    break;
                }
                else {
                    std::cout << "�� ������������." << std::endl;
                    break;
                }
            case 2:
                chance = rand() % 100;
                if (chance < body_chance) {
                    std::cout << "�� ������� ���� � ����" << std::endl;
                    std::cout << "����� ������� ���� �� " << int(dmg * 0.7) << " �����." << std::endl;
                    enemy_hp -= int(dmg * 0.7);
                    break;
                }
                else {
                    std::cout << "�� ������������." << std::endl;
                    break;
                }
            case 3:
                chance = rand() % 100;
                if (chance < arm_chance) {
                    std::cout << "�� ������� ���� � ����" << std::endl;
                    std::cout << "����� ������� ���� �� " << int(dmg * 0.7) << " �����." << std::endl;
                    std::cout << "��������� ������ ������� �� 30% ������ �����" << std::endl;
                    enemy_hp -= int(dmg * 0.4);
                    enemy_dmg *= 0.7;
                    break;
                }
                else {
                    std::cout << "�� ������������." << std::endl;
                    break;
                }
            }
            std::cout << "��������� ����� ��� " << enemy_dmg << " �����." << std::endl;
            hp -= enemy_dmg;
            if (hp < 1) {
                std::cout << "��� �����.";
            }
            if (enemy_hp < 1) {
                std::cout << "�� �������� ����������!" << std::endl;
                std::cout << "�������� " << enemy_money << " �����." << std::endl;
                money += enemy_money;
                if ((lvl_number + 1) == n) {
                    std::cout << "�� �������� ������������� ������!\n������ �� �� ��������� �����. " << std::endl;
                }
                else {
                    std::cout << "��������� " << enemy_exp << " �����." << std::endl;
                    exp += enemy_exp;
                    if (exp >= lvlexp) {
                        exp = exp - lvlexp;
                        lvl_number = lvl_number + 1;
                        std::cout << "����������! �� �������� " << lvl_number + 1 << " ������." << std::endl;
                        hp = lvlhp + hp_item - goddamn;
                    }
                }
                break;
            }
        }
    }
}
void fountain(int& money, int& hp, int& lvl_number, int lvl_hp[], int hp_item, int& goddamn) {
    setlocale(LC_ALL, "rus");
    int comand;
    std::cout << "�� ������� � ������.\n�� �������� ����� ���� ���� ���������: \n����� ������ ������ �� ���������� �������, ������, ������ �� ��������� 30 �����, � ���� ������ ������ ������ �������!�" << std::endl << std::endl;
    std::cout << "���� ���������� �����: " << money << std::endl << std::endl;
    std::cout << "1) ���������.\n2) �� �������.\n0) ����." << std::endl << std::endl;
    std::cin >> comand;
    std::cout << std::endl;
    switch (comand) {
    case 0:break;
    case 1:
        if (money >= 30) {
            std::cout << "�� ����������." << std::endl << std::endl;
            hp = lvl_hp[lvl_number] + hp_item - goddamn;
            money -= 30;
        }
        else {
            std::cout << "� ��� ������������ �����." << std::endl << std::endl;
        }
        break;
    case 2:
        std::cout << "�� ����������.\n���� ������������ ���������� �������� ���������� �� 10 ������." << std::endl << std::endl;
        goddamn += 10;
        hp = lvl_hp[lvl_number] + hp_item - goddamn;
        if (hp < 1) {
            std::cout << "��� �������� ��������." << std::endl;
        }
        break;
    }
}
void smith(int& money, int& shop, int& shop_money, int& shop_hp_item, int& shop_dmg_item, int& comand, int& hp_item, int& dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name)
{
    setlocale(LC_ALL, "rus");
    std::cout << "����������� ������! ���-�� ������ ���������?\n";
    while (comand != 0)
    {
        int comand;
        wepon_and_armor w_and_a;
        std::cout << "� ��� " << money << " �����.\n\n";
        std::cout << "1) ������ �������� �������         +5  � �����              40 �����.\n2) ������ �������� ���             +15 � �����             150 �����.\n";
        std::cout << "3) ������ ������� �����            +50 � �����              70 �����.\n4) ������ �������� �����          +250 � �����             300 �����.\n";
        std::cout << "0) ����� �� �������.\n\n";
        std::cin >> comand;
        std::cout << std::endl;

        switch (comand) {
        case 0:
            shop = 0;
            break;
        case SMITH_COMMAND_IRON_CLUB:
            shop_money = w_and_a.weapon_money_iron_club;
            shop_name = "�������� �������";
            shop_dmg_item = w_and_a.weapon_dmg_iron_club;
            shop = 1; break;
        case SMITH_COMMAND_STEEL_SWORD:
            shop_money = w_and_a.weapon_money_steel_sword;
            shop_name = "�������� ���";
            shop_dmg_item = w_and_a.weapon_dmg_steel_sword;
            shop = 1; break;
        case SMITH_COMMAND_LEATHER_ARMOR:
            shop_money = w_and_a.armor_money_leather_armor;
            shop_name = "������� �����";
            shop_hp_item = w_and_a.armor_hp_leather_armor;
            shop = 2; break;
        case SMITH_COMMAND_IRON_ARMOR:
            shop_money = w_and_a.weapon_money_iron_club;
            shop_name = "�������� �����./n";
            shop_hp_item = w_and_a.armor_hp_iron_armor;
            shop = 2; break;
        }
        if (shop == 0) {
            break;
        }
        else if (money < shop_money) {
            std::cout << "�� ������� �����." << std::endl;
        }
        else {
            if (shop == 1) {
                if (weapon_name == shop_name) {
                    std::cout << "� ��� ���� ��� ������." << std::endl;
                }
                else {
                    weapon_name = shop_name;
                    dmg_item = shop_dmg_item;
                    money -= shop_money;
                }
            }
            else if (shop == 2) {
                if (armor_name == shop_name) {
                    std::cout << "� ��� ���� ��� �����." << std::endl;
                }
                else {
                    armor_name = shop_name;
                    hp_item = shop_hp_item;
                    money -= shop_money;
                }
            }
        }
    }

}
void recruitment_of_the_enemy(int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& enemy_money, int& enemy, int& lvl_number)
{
    setlocale(LC_ALL, "rus");
    enemy = rand() % 100;
    EnemyAndCo enemies;
    if (enemy >= 0 && enemy <= 6)
    {
        std::cout << "�� ���������� �� ������." << std::endl;
        enemy_hp = enemies.enemy_wood_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_wood_dmg;
        enemy_exp = enemies.enemy_wood_exp;
        enemy_money = enemies.enemy_wood_money;
    }
    else if (enemy >= 7 && enemy <= 20)
    {
        std::cout << "� ������ �������� ����." << std::endl;
        enemy_hp = enemies.enemy_elf_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_elf_dmg;
        enemy_exp = enemies.enemy_elf_exp;
        enemy_money = enemies.enemy_elf_money;
    }
    else if (enemy >= 21 && enemy <= 41)
    {
        std::cout << "��� ����� ������� �� ��� ���." << std::endl;
        enemy_hp = enemies.enemy_ogr_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_ogr_dmg;
        enemy_exp = enemies.enemy_ogr_dmg;
        enemy_money = enemies.enemy_ogr_money;
    }
    else if (enemy >= 42 && enemy <= 68)
    {
        std::cout << "�� ��� ����� ����� ��� ." << std::endl;
        enemy_hp = enemies.enemy_wild_dog_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_wild_dog_dmg;
        enemy_exp = enemies.enemy_wild_dog_exp;
        enemy_money = enemies.enemy_wild_dog_money;
    }
    else if (enemy >= 69 && enemy <= 92)
    {
        std::cout << "�� ����� ��������� �������." << std::endl;
        enemy_hp = enemies.enemy_slizen_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_slizen_dmg;
        enemy_exp = enemies.enemy_slizen_exp;
        enemy_money = enemies.enemy_slizen_money;
    }
    else if (enemy >= 93 && enemy <= 99)
        std::cout << "��������� �� ������.\n\n";
}
void specifications(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg, std::string weapon_name, std::string armor_name, std::string shop_name, int& lvl_number, int& exp, int& comand, int& hp, int& hp_item, int& goddamn, int& dmg, int& dmg_item, int& enemy, int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& money, int& shop, int& shop_money, int& enemy_money, int& shop_hp_item, int& shop_dmg_item)
{
    lvl_number = 0, exp = 0, comand; //������
    hp = 100, hp_item = 0, goddamn = 0; //�����
    dmg, dmg_item = 0;  //����
    enemy = 0, enemy_hp = 0, enemy_dmg = 0, enemy_exp = 0; //����
    money = 0, shop = 0, shop_money = 0, enemy_money = 0, shop_hp_item = 0, shop_dmg_item = 0; //�������

    for (int i = 0; i < n; i++)
        lvl[i] = i + 1;
    for (int i = 0; i < n; i++)
        lvl_hp[i] = 25 * i + 100;
    int lvl_exp1[10] = { 10,25,45,70,85,100,130,170,200,250 };//���� ��� ��������������� ������
    for (int i = 0; i < n; i++)
    {
        lvl_exp[i] = lvl_exp1[i];
    }
    int lvl_dmg1[10] = { 3,5,9,12,15,19,24,28,35,40 };//���� ��� ��������������� ������
    for (int i = 0; i < n; i++)
    {
        lvl_dmg[i] = lvl_dmg1[i];
    }
}
void Game_Loop(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg, std::string weapon_name, std::string armor_name, std::string shop_name, int& lvl_number, int& exp, int& comand, int& hp, int& hp_item, int& goddamn, int& dmg, int& dmg_item, int& enemy, int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& money, int& shop, int& shop_money, int& enemy_money, int& shop_hp_item, int& shop_dmg_item)
{
    setlocale(LC_ALL, "rus");
    while (hp > 0) { //���� ����
        dmg = lvl_dmg[lvl_number] + dmg_item;
        std::cout << "������� ����� ��� ������ �������:\n1) ������� ���������� � �����.\n2) ����������� � ���.\n3) ����� � �������.\n4) ���� � �������.\n\n";
        std::cin >> comand;
        std::cout << std::endl;
        switch (comand) {
        case 1:         //����� ������� ���������� � �����.
            info(n, lvl_number, lvl, lvl_exp, exp, hp, dmg, money, weapon_name, armor_name, goddamn);
            break;
        case 2:         //��� � ����� ����������
            recruitment_of_the_enemy(enemy_hp, enemy_dmg, enemy_exp, enemy_money, enemy, lvl_number);
            //����� ������� �����
            if (enemy >= 0 && enemy <= 92) {
                battle(enemy, hp, enemy_hp, dmg, enemy_dmg, money, enemy_money, lvl_number, n, enemy_exp, exp, &lvl_exp[lvl_number], &lvl_hp[lvl_number], hp_item, goddamn);
            }
            std::cout << std::endl; break;
        case 3: //������
            smith(money, shop, shop_money, shop_hp_item, shop_dmg_item, comand, hp_item, dmg_item, weapon_name, armor_name, shop_name);
            std::cout << std::endl;
            break;
        case 4: //����� ������� �������
            fountain(money, hp, lvl_number, &lvl_hp[lvl_number], hp_item, goddamn);
            break;
        }
    }
}