#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Components.h"
#include "Class.h"
const int n = 10;




int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    std::string weapon_name = "Тренировочные перчатки", armor_name = "Тряпье", shop_name, hero_name; //Названия
    int lvl_number, exp, comand;
    int hp, hp_item, goddamn;
    int dmg, dmg_item;
    int enemy, enemy_hp, enemy_dmg, enemy_exp;
    int money, shop, shop_money, enemy_money, shop_hp_item, shop_dmg_item;
    int lvl[10];//Уровни
    int lvl_hp[10];//Жизнь при соответственном уровне
    int lvl_exp[10];//Опыт при соответственном уровне
    int lvl_dmg[10];//Урон при соответственном уровне
    specifications(n, lvl, lvl_hp, lvl_exp, lvl_dmg, weapon_name, armor_name, shop_name, lvl_number, exp, comand, hp, hp_item, goddamn, dmg, dmg_item, enemy, enemy_hp, enemy_dmg, enemy_exp, money, shop, shop_money, enemy_money, shop_hp_item, shop_dmg_item);
    Game_Loop(n, lvl, lvl_hp, lvl_exp, lvl_dmg, weapon_name, armor_name, shop_name, lvl_number, exp, comand, hp, hp_item, goddamn, dmg, dmg_item, enemy, enemy_hp, enemy_dmg, enemy_exp, money, shop, shop_money, enemy_money, shop_hp_item, shop_dmg_item);
    system("PAUSE");
    return 0;
}

