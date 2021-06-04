#pragma once
//Информация о персонаже
void info(const int n, int& lvl_number, int lvl[10], int lvl_exp[10], int& exp, int& hp, int& dmg, int& money, std::string weapon_name, std::string armor_name, int& goddamn);
//Система битвы
void battle(int& enemy, int& hp, int& enemy_hp, int& dmg, int& enemy_dmg, int& money, int& enemy_money, int& lvl_number, const int n, int& enemy_exp, int& exp, int lvl_exp[], int lvl_hp[], int& hp_item, int& goddamn);
// Фонтан
void fountain(int& money, int& hp, int& lvl_number, int lvl_hp[], int hp_item, int& goddamn);
//Кузнец
void smith(int& money, int& shop, int& shop_money, int& shop_hp_item, int& shop_dmg_item, int& comand, int& hp_item, int& dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name);
//Подбор
void recruitment_of_the_enemy(int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& enemy_money, int& enemy, int& lvl_number);
//Начальная инициализация
void specifications(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg, std::string weapon_name, std::string armor_name, std::string shop_name, int& lvl_number, int& exp, int& comand, int& hp, int& hp_item, int& goddamn, int& dmg, int& dmg_item, int& enemy, int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& money, int& shop, int& shop_money, int& enemy_money, int& shop_hp_item, int& shop_dmg_item);
//Цикл игры
void Game_Loop(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg, std::string weapon_name, std::string armor_name, std::string shop_name, int& lvl_number, int& exp, int& comand, int& hp, int& hp_item, int& goddamn, int& dmg, int& dmg_item, int& enemy, int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& money, int& shop, int& shop_money, int& enemy_money, int& shop_hp_item, int& shop_dmg_item);