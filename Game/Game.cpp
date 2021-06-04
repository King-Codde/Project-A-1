#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
const int n = 10;
int lvl[10];//Уровни
int lvl_hp[10];//Жизнь при соответственном уровне
int lvl_exp[10];//Опыт при соответственном уровне
int lvl_dmg[10];//Урон при соответственном уровне

void lvl_inic(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg)
{
    for (int i = 0; i < n; i++)
        lvl[i] = i + 1;
    for (int i = 0; i < n; i++)
        lvl_hp[i] = 25 * i + 100;
    int lvl_exp1[10] = { 10,25,45,70,85,100,130,170,200,250 };//Опыт при соответственном уровне
    for (int i = 0; i < n; i++)
    {
        lvl_exp[i] = lvl_exp1[i];
    }
    int lvl_dmg1[10] = { 3,5,9,12,15,19,24,28,35,40 };//Урон при соответственном уровне
    for (int i = 0; i < n; i++)
    {
        lvl_dmg[i] = lvl_dmg1[i];
    }
}

//Команды для Кузни
class COMMAND
{
public:
    int my_command = 0;
};
//Команды для Кузни
enum SMITH_COMMAN
{
    SMITH_COMMAND_IRON_CLUB = 1,
    SMITH_COMMAND_STEEL_SWORD = 2,
    SMITH_COMMAND_LEATHER_ARMOR = 3,
    SMITH_COMMAND_IRON_ARMOR = 4,
};

class EnemyAndCo
{
public:
    int enemy_ogr_hp = 15;
    int enemy_ogr_dmg = 6;
    int enemy_ogr_exp = 6;
    int enemy_ogr_money = 14;

    int enemy_elf_hp = 8;
    int enemy_elf_dmg = 12;
    int enemy_elf_exp = 8;
    int enemy_elf_money = 17;

    int enemy_wood_hp = 18;
    int enemy_wood_dmg = 8;
    int enemy_wood_exp = 7;
    int enemy_wood_money = 20;

    int enemy_slizen_hp = 10;
    int enemy_slizen_dmg = 4;
    int enemy_slizen_exp = 4;
    int enemy_slizen_money = 10;

    int enemy_wild_dog_hp = 5;
    int enemy_wild_dog_dmg = 4;
    int enemy_wild_dog_exp = 2;
    int enemy_wild_dog_money = 5;

};
class wepon_and_armor
{
public:
    int weapon_money_iron_club = 40;
    int weapon_dmg_iron_club = 5;
    int weapon_money_steel_sword = 150;
    int weapon_dmg_steel_sword = 15;
    int armor_money_leather_armor = 70;
    int armor_hp_leather_armor = 50;
    int armor_money_iron_armor = 300;
    int armor_hp_iron_armor = 250;
};

class hero
{
public:
    int hp = 100;
    int dmg = 0;
    int exp = 0;
    int money = 0;
    int goddamn = 0;
    int lvl_number = 0;
    int dmg_item = 0;
    int hp_item = 0;
    int shop = 0;
    std::string weapon_name = "Тренировочные перчатки";
    std::string armor_name = "Тряпье";
    std::string shop_name;
    //void info(const int n, int& lvl_number, int lvl[10], int lvl_exp[10], int& exp, int& hp, int& dmg, int& money, std::string weapon_name, std::string armor_name, int& goddamn);
    void info(const int n, int& lvl_number, int lvl[10], int lvl_exp[10], int& exp, int& hp, int& dmg, int& money, std::string weapon_name, std::string armor_name, int& goddamn);

};

class enemy_characteristic
{
public:
    int enemy = 0;
    int enemy_hp = 0;
    int enemy_dmg = 0;
    int enemy_exp = 0;
    int enemy_money = 0;
};

class shop_smith
{
public:
    int shop_money = 0;
    int shop_hp_item = 0;
    int shop_dmg_item = 0;
    int shop_name = 0;


};

struct fountain
{
    void fountain_(int& money, int& hp, int& lvl_number, int lvl_hp[], int hp_item, int& goddamn);
};

struct smith
{
    shop_smith smith_;
    int shop_money = smith_.shop_money;
    int shop_hp_items = smith_.shop_hp_item;
    int shop_dmg_items = smith_.shop_dmg_item;
    int shop_name = smith_.shop_name;


    void shoop(int& money, int& shop, int& shop_money, int& shop_hp_item, int& shop_dmg_item, int& comand, int& hp_item, int& dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name);
};

struct buttle
{
    enemy_characteristic enemy_charac;
    int enemy = enemy_charac.enemy;
    int enemy_hp = enemy_charac.enemy_hp;
    int enemy_dmg = enemy_charac.enemy_dmg;
    int enemy_exp = enemy_charac.enemy_exp;
    int enemy_money = enemy_charac.enemy_money;


    void recruitment_of_the_enemy(int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& enemy_money, int& enemy, int& lvl_number);
    void battle(int& enemy, int& hp, int& enemy_hp, int& dmg, int& enemy_dmg, int& money, int& enemy_money, int& lvl_number, const int n, int& enemy_exp, int& exp, int lvl_exp[], int lvl_hp[], int& hp_item, int& goddamn);

};


void buttle::recruitment_of_the_enemy(int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& enemy_money, int& enemy, int& lvl_number)
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    enemy = rand() % 100;
    EnemyAndCo enemies;
    if (enemy >= 0 && enemy <= 6)
    {
        std::cout << "Вы наткнулись на лешого." << std::endl;
        enemy_hp = enemies.enemy_wood_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_wood_dmg;
        enemy_exp = enemies.enemy_wood_exp;
        enemy_money = enemies.enemy_wood_money;
    }
    else if (enemy >= 7 && enemy <= 20)
    {
        std::cout << "С дерева спрыгнул эльф." << std::endl;
        enemy_hp = enemies.enemy_elf_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_elf_dmg;
        enemy_exp = enemies.enemy_elf_exp;
        enemy_money = enemies.enemy_elf_money;
    }
    else if (enemy >= 21 && enemy <= 41)
    {
        std::cout << "Огр хочет сделать из вас суп." << std::endl;
        enemy_hp = enemies.enemy_ogr_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_ogr_dmg;
        enemy_exp = enemies.enemy_ogr_dmg;
        enemy_money = enemies.enemy_ogr_money;
    }
    else if (enemy >= 42 && enemy <= 68)
    {
        std::cout << "На вас напал дикий пес ." << std::endl;
        enemy_hp = enemies.enemy_wild_dog_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_wild_dog_dmg;
        enemy_exp = enemies.enemy_wild_dog_exp;
        enemy_money = enemies.enemy_wild_dog_money;
    }
    else if (enemy >= 69 && enemy <= 92)
    {
        std::cout << "Из куста выпрыгнул слизень." << std::endl;
        enemy_hp = enemies.enemy_slizen_hp * (lvl_number + 1);
        enemy_dmg = enemies.enemy_slizen_dmg;
        enemy_exp = enemies.enemy_slizen_exp;
        enemy_money = enemies.enemy_slizen_money;
    }
    else if (enemy >= 93 && enemy <= 99)
        std::cout << "Противник не найден.\n\n";

}
void buttle::battle(int& enemy, int& hp, int& enemy_hp, int& dmg, int& enemy_dmg, int& money, int& enemy_money, int& lvl_number, const int n, int& enemy_exp, int& exp, int lvl_exp[], int lvl_hp[], int& hp_item, int& goddamn)
{
    setlocale(LC_ALL, "rus");
    int hit;
    int lvlexp = lvl_exp[lvl_number];
    int lvlhp = lvl_hp[lvl_number];
    int chance, head_chance = 35, body_chance = 80, arm_chance = 42;
    if (enemy != 0) {
        while (hp > 0) {
            std::cout << "Ваше количество жизни " << hp << "." << std::endl;
            std::cout << "Количество жизней противника " << enemy_hp << "." << std::endl;
            std::cout << "Выберете куда нанести удар\n1) Голова\n2) Тело\n3) Руки" << std::endl;
            std::cin >> hit;
            switch (hit)
            {
            case 1:
                chance = rand() % 100;
                if (chance < head_chance) {
                    std::cout << "Вы нанесли удар в голову" << std::endl;
                    std::cout << "Герой наносит удар на " << dmg << " урона." << std::endl;
                    enemy_hp -= dmg;
                    break;
                }
                else {
                    std::cout << "Вы промахнулись." << std::endl;
                    break;
                }
            case 2:
                chance = rand() % 100;
                if (chance < body_chance) {
                    std::cout << "Вы нанесли удар в тело" << std::endl;
                    std::cout << "Герой наносит удар на " << int(dmg * 0.7) << " урона." << std::endl;
                    enemy_hp -= int(dmg * 0.7);
                    break;
                }
                else {
                    std::cout << "Вы промахнулись." << std::endl;
                    break;
                }
            case 3:
                chance = rand() % 100;
                if (chance < arm_chance) {
                    std::cout << "Вы нанесли удар в руку" << std::endl;
                    std::cout << "Герой наносит удар на " << int(dmg * 0.7) << " урона." << std::endl;
                    std::cout << "Противник теперь наносит на 30% меньше урона" << std::endl;
                    enemy_hp -= int(dmg * 0.4);
                    enemy_dmg *= 0.7;
                    break;
                }
                else {
                    std::cout << "Вы промахнулись." << std::endl;
                    break;
                }
            }
            std::cout << "Противник нанес вам " << enemy_dmg << " урона." << std::endl;
            hp -= enemy_dmg;
            if (hp < 1) {
                std::cout << "Вас убили.";
            }
            if (enemy_hp < 1) {
                std::cout << "Вы победили противника!" << std::endl;
                std::cout << "Получено " << enemy_money << " монет." << std::endl;
                money += enemy_money;
                if ((lvl_number + 1) == n) {
                    std::cout << "Вы достигли максимального уровня!\nБольше вы не получаете опыта. " << std::endl;
                }
                else {
                    std::cout << "Полученно " << enemy_exp << " опыта." << std::endl;
                    exp += enemy_exp;
                    if (exp >= lvlexp) {
                        exp = exp - lvlexp;
                        lvl_number = lvl_number + 1;
                        std::cout << "Поздравляю! Вы достигли " << lvl_number + 1 << " уровня." << std::endl;
                        hp = lvlhp + hp_item - goddamn;
                    }
                }
                break;
            }
        }
    }
}
void hero::info(const int n, int& lvl_number, int lvl[10], int lvl_exp[10], int& exp, int& hp, int& dmg, int& money, std::string weapon_name, std::string armor_name, int& goddamn)
{
    setlocale(LC_ALL, "rus");
    std::cout << "Ваш уровень " << lvl[lvl_number] << "." << std::endl;
    if (lvl_number + 1 != n) {
        std::cout << "До нового уровня осталось " << lvl_exp[lvl_number] - exp << " опыта." << std::endl;
    }
    else {
        std::cout << "До нового уровня осталось 0 опыта." << std::endl;
    }
    std::cout << "Ваше количество проклятий " << goddamn / 10 << ". " << "Ваше здоровье будет уменьшенно на " << goddamn << "." << std::endl;
    std::cout << "Ваше здоровье " << hp << "." << std::endl;
    std::cout << "Ваш урон " << dmg << "." << std::endl;
    std::cout << "Количнство монет " << money << "." << std::endl;
    std::cout << "Ваше оружие " << weapon_name << "." << std::endl;
    std::cout << "Ваша броня " << armor_name << "." << std::endl << std::endl;
}
void smith::shoop(int& money, int& shop, int& shop_money, int& shop_hp_item, int& shop_dmg_item, int& comand, int& hp_item, int& dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name)
{
    setlocale(LC_ALL, "rus");
    std::cout << "Приветствую путник! Что-то хочешь прикупить?\n";
    while (comand != 0)
    {
        int comand;
        wepon_and_armor w_and_a;
        COMMAND my_command;
        std::cout << "У вас " << money << " монет.\n\n";
        std::cout << "1) Купить Железная Дубинка         +5  к атаке              40 монет.\n2) Купить Стальной Меч             +15 к атаке             150 монет.\n";
        std::cout << "3) Купить Кожаная броня            +50 к жизни              70 монет.\n4) Купить Железная броня          +250 к жизни             300 монет.\n";
        std::cout << "0) Выйти из кузнецы.\n\n";
        std::cin >> comand;
        std::cout << std::endl;

        switch (comand) {
        case 0:
            shop = 0;
            break;
        case SMITH_COMMAND_IRON_CLUB:
            shop_money = w_and_a.weapon_money_iron_club;
            shop_name = "Железная Дубинка";
            shop_dmg_item = w_and_a.weapon_dmg_iron_club;
            shop = 1; break;
        case SMITH_COMMAND_STEEL_SWORD:
            shop_money = w_and_a.weapon_money_steel_sword;
            shop_name = "Стальной Меч";
            shop_dmg_item = w_and_a.weapon_dmg_steel_sword;
            shop = 1; break;
        case SMITH_COMMAND_LEATHER_ARMOR:
            shop_money = w_and_a.armor_money_leather_armor;
            shop_name = "Кожаная броня";
            shop_hp_item = w_and_a.armor_hp_leather_armor;
            shop = 2; break;
        case SMITH_COMMAND_IRON_ARMOR:
            shop_money = w_and_a.weapon_money_iron_club;
            shop_name = "Железная броня./n";
            shop_hp_item = w_and_a.armor_hp_iron_armor;
            shop = 2; break;
        }
        if (shop == 0) {
            break;
        }
        else if (money < shop_money) {
            std::cout << "Не хватает денег." << std::endl;
        }
        else {
            if (shop == 1) {
                if (weapon_name == shop_name) {
                    std::cout << "У вас есть это оружие." << std::endl;
                }
                else {
                    weapon_name = shop_name;
                    dmg_item = shop_dmg_item;
                    money -= shop_money;
                }
            }
            else if (shop == 2) {
                if (armor_name == shop_name) {
                    std::cout << "У вас есть эта броня." << std::endl;
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
void fountain::fountain_(int& money, int& hp, int& lvl_number, int lvl_hp[], int hp_item, int& goddamn)
{
    setlocale(LC_ALL, "rus");
    int comand;
    std::cout << "Вы подошли к фотану.\nНа табличке возле него было написанно: \n„Коли хочешь испить из волшебного фонтана, путник, должен ты заплатить 30 монет, в ином случае будешь навеки проклят!“" << std::endl << std::endl;
    std::cout << "Ваше количество монет: " << money << std::endl << std::endl;
    std::cout << "1) Заплатить.\n2) Не платить.\n0) Уйти." << std::endl << std::endl;
    std::cin >> comand;
    std::cout << std::endl;
    switch (comand) {
    case 0:break;
    case 1:
        if (money >= 30) {
            std::cout << "Вы исцелились." << std::endl << std::endl;
            hp = lvl_hp[lvl_number] + hp_item - goddamn;
            money -= 30;
        }
        else {
            std::cout << "У вас недостатачно монет." << std::endl << std::endl;
        }
        break;
    case 2:
        std::cout << "Вы исцелились.\nВаше максимальное количество здоровья уменьшенно на 10 единиц." << std::endl << std::endl;
        goddamn += 10;
        hp = lvl_hp[lvl_number] + hp_item - goddamn;
        if (hp < 1) {
            std::cout << "Вас погубила жадность." << std::endl;
        }
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    hero Amin;
    buttle my_buttle;
    smith smith_2;
    fountain my_fountain;
    lvl_inic(n, lvl, lvl_hp, lvl_exp, lvl_dmg);
    while (Amin.hp > 0) { //Цикл игры
        Amin.dmg = lvl_dmg[Amin.lvl_number] + Amin.dmg_item;
        std::cout << "Введите цифру что хотите сделать:\n1) Открыть информацию о герое.\n2) Отправиться в лес.\n3) Зайти к Кузнецу.\n4) Идти к фонтану.\n\n";
        COMMAND my_choice;
        std::cin >> my_choice.my_command;
        std::cout << std::endl;
        switch (my_choice.my_command) {
        case 1:         //Вызов функции информации о герое.
            Amin.info(n, Amin.lvl_number, lvl, lvl_exp, Amin.exp, Amin.hp, Amin.dmg, Amin.money, Amin.weapon_name, Amin.armor_name, Amin.goddamn);
            break;
        case 2:         //Лес и выбор противника
            my_buttle.recruitment_of_the_enemy(my_buttle.enemy_hp, my_buttle.enemy_dmg, my_buttle.enemy_exp, my_buttle.enemy_money, my_buttle.enemy, Amin.lvl_number);
            //Вызов функции битвы
            if (my_buttle.enemy >= 0 && my_buttle.enemy <= 92) {
                my_buttle.battle(my_buttle.enemy, Amin.hp, my_buttle.enemy_hp, Amin.dmg, my_buttle.enemy_dmg, Amin.money, my_buttle.enemy_money, Amin.lvl_number, n, my_buttle.enemy_exp, Amin.exp, &lvl_exp[Amin.lvl_number], &lvl_hp[Amin.lvl_number], Amin.hp_item, Amin.goddamn);
            }
            std::cout << std::endl; break;
        case 3: //Кузнец
            smith_2.shoop(Amin.money, Amin.shop, smith_2.shop_money, smith_2.shop_hp_items, smith_2.shop_dmg_items, my_choice.my_command, Amin.hp_item, Amin.dmg_item, Amin.weapon_name, Amin.armor_name, Amin.shop_name);
            std::cout << std::endl;
            break;
        case 4: //Вызов функции фонтана
            my_fountain.fountain_(Amin.money, Amin.hp, Amin.lvl_number, &lvl_hp[Amin.lvl_number], Amin.hp_item, Amin.goddamn);
            break;
        }
    }


}
