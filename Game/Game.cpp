#include <iostream>
#include <cstdlib>
#include <ctime>
const int n = 10;
//Система битвы
void battle(int& enemy, int& hp, int& enemy_hp, int& dmg, int& enemy_dmg, int& money, int& enemy_money, int& lvl_number, const int n, int& enemy_exp, int& exp, int lvl_exp[], int lvl_hp[], int& hp_item, int& goddamn);
//Информация о герое.
void info(const int n, int &lvl_number, int lvl[10], int lvl_exp[10], int &exp, int &hp, int &dmg, int &money, std::string weapon_name, std::string armor_name, int &goddamn);
//Фонтан
void fountain(int& money, int& hp, int& lvl_number, int lvl_hp[], int hp_item, int& goddamn);
//Кузнец
void smith(int& money, int& shop, int& shop_money, int& shop_hp_item, int& shop_dmg_item, int& comand, int& hp_item, int& dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name);
//Подбор противника
void recruitment_of_the_enemy(int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& enemy_money, int& enemy, int& lvl_number);
//Начальные характеристики
void specifications(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg, std::string weapon_name, std::string armor_name, std::string shop_name, int& lvl_number, int& exp, int& comand, int& hp, int& hp_item, int& goddamn, int& dmg, int& dmg_item, int& enemy, int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& money, int& shop, int& shop_money, int& enemy_money, int& shop_hp_item, int& shop_dmg_item);
//Монстры
enum ENEMIES
{
    ENEMIES_OGR_hp = 15,
    ENEMIES_OGR_dmg = 6,
    ENEMIES_OGR_exp = 6,
    ENEMIES_OGR_money = 14,
    ENEMIES_ELF_hp = 8,
    ENEMIES_ELF_dmg = 12,
    ENEMIES_ELF_exp = 8,
    ENEMIES_ELF_money = 17,
    ENEMIES_WOOD_GOBLIN_hp = 18,
    ENEMIES_WOOD_GOBLIN_dmg = 8,
    ENEMIES_WOOD_GOBLIN_exp = 7,
    ENEMIES_WOOD_GOBLIN_money = 20,
    ENEMIES_SLIZEN_hp = 10,
    ENEMIES_SLIZEN_dmg = 4,
    ENEMIES_SLIZEN_exp = 4,
    ENEMIES_SLIZEN_money = 10,
    ENEMIES_WILD_DOG_hp = 5,
    ENEMIES_WILD_DOG_dmg = 4,
    ENEMIES_WILD_DOG_exp = 2,
    ENEMIES_WILD_DOG_money = 5,
};
//Оружие и Броня
enum WEAPON_AND_ARMOR
{
    WEAPON_money_IRON_CLUB = 40,
    WEAPON_dmg_IRON_CLUB = 5,
    WEAPON_money_STEEL_SWORD = 150,
    WEAPON_dmg_STEEL_SWORD = 15,
    ARMOR_money_LEATHER_ARMOR = 70,
    ARMOR_hp_LEATHER_ARMOR = 50,
    ARMOR_money_IRON_ARMOR = 300,
    ARMOR_hp_IRON_ARMOR = 250,
};
//Команды для Кузни
enum SMITH_COMMAND
{
    SMITH_COMMAND_IRON_CLUB = 1,
    SMITH_COMMAND_STEEL_SWORD = 2,
    SMITH_COMMAND_LEATHER_ARMOR = 3,
    SMITH_COMMAND_IRON_ARMOR = 4,
};

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    std::string weapon_name = "Тренировочные перчатки", armor_name = "Тряпье", shop_name; //Названия
    int lvl_number,exp,comand;
    int hp,hp_item,goddamn; 
    int dmg,dmg_item;  
    int enemy,enemy_hp,enemy_dmg,enemy_exp; 
    int money,shop,shop_money,enemy_money,shop_hp_item,shop_dmg_item;  
    int lvl[10];//Уровни
    int lvl_hp[10];//Жизнь при соответственном уровне
    int lvl_exp[10];//Опыт при соответственном уровне
    int lvl_dmg[10];//Урон при соответственном уровне
    specifications(n,lvl, lvl_hp, lvl_exp, lvl_dmg,weapon_name,armor_name,shop_name, lvl_number,exp,comand,hp,hp_item,goddamn,dmg,dmg_item,enemy,enemy_hp,enemy_dmg,enemy_exp,money,shop,shop_money,enemy_money,shop_hp_item,shop_dmg_item);
    while (hp > 0) { //Цикл игры
        dmg = lvl_dmg[lvl_number] + dmg_item;
        std::cout << "Введите цифру что хотите сделать:\n1) Открыть информацию о герое.\n2) Отправиться в лес.\n3) Зайти к Кузнецу.\n4) Идти к фонтану.\n\n";
        std::cin >> comand;
        std::cout << std::endl;
        switch (comand) {
        case 1:         //Вызов функции информации о герое.
            info(n, lvl_number, lvl, lvl_exp, exp, hp, dmg, money, weapon_name, armor_name,goddamn);
            break;
        case 2:         //Лес и выбор противника
            recruitment_of_the_enemy( enemy_hp, enemy_dmg, enemy_exp,enemy_money,enemy, lvl_number);
            //Вызов функции битвы
            if (enemy >= 0 && enemy <= 92) {
                battle(enemy, hp, enemy_hp, dmg, enemy_dmg, money, enemy_money, lvl_number, n, enemy_exp, exp, &lvl_exp[lvl_number], &lvl_hp[lvl_number], hp_item, goddamn);
            }
            std::cout << std::endl; break;
        case 3: //Кузнец
            smith(money,shop, shop_money, shop_hp_item,shop_dmg_item,comand, hp_item,dmg_item, weapon_name, armor_name, shop_name);
            std::cout << std::endl;
            break;
        case 4: //Вызов функции фонтана
            fountain(money, hp, lvl_number, &lvl_hp[lvl_number], hp_item,goddamn);
            break;
        }
    }
    system("PAUSE");
    return 0;
}



//Информация о герое.
void info(const int n, int &lvl_number, int lvl[10], int lvl_exp[10], int &exp, int &hp, int &dmg, int &money, std::string weapon_name, std::string armor_name, int &goddamn) {
    std::cout << "Ваш уровень " << lvl[lvl_number] << "." << std::endl;
    if (lvl_number + 1 != n) {
        std::cout << "До нового уровня осталось " << lvl_exp[lvl_number] - exp << " опыта." << std::endl;
    }
    else {
        std::cout << "До нового уровня осталось 0 опыта." << std::endl;
    }
    std::cout << "Ваше количество проклятий " << goddamn/10 <<". " << "Ваше здоровье будет уменьшенно на " << goddamn <<"." << std::endl;
    std::cout << "Ваше здоровье " << hp << "." << std::endl;
    std::cout << "Ваш урон " << dmg << "." << std::endl;
    std::cout << "Количнство монет " << money << "." << std::endl;
    std::cout << "Ваше оружие " << weapon_name << "." << std::endl;
    std::cout << "Ваша броня " << armor_name << "." << std::endl << std::endl;
}

//Система битвы
void battle(int &enemy, int &hp, int &enemy_hp, int &dmg, int &enemy_dmg, int &money, int &enemy_money, int &lvl_number, const int n, int &enemy_exp, int &exp, int lvl_exp[], int lvl_hp[], int &hp_item, int &goddamn) {
    int hit;
    int lvlexp = lvl_exp[lvl_number];
    int lvlhp = lvl_hp[lvl_number];
    int chance, head_chance=35, body_chance=80, arm_chance=42;
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

//Фонтан
void fountain(int &money, int &hp, int & lvl_number, int lvl_hp[], int hp_item,int &goddamn) {
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
            hp = lvl_hp[lvl_number] + hp_item-goddamn;
            money -= 30;
        }
        else {
            std::cout << "У вас недостатачно монет." << std::endl << std::endl;
        }
        break;
    case 2:
        std::cout << "Вы исцелились.\nВаше максимальное количество здоровья уменьшенно на 10 единиц." << std::endl << std::endl;
        goddamn += 10;
        hp = lvl_hp[lvl_number] + hp_item-goddamn;
        if (hp < 1) {
            std::cout << "Вас погубила жадность." << std::endl;
        }
        break;
    }
}

//Кузнец
void smith(int &money, int &shop, int &shop_money, int &shop_hp_item, int &shop_dmg_item, int &comand, int &hp_item, int &dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name)
{
    std::cout << "Приветствую путник! Что-то хочешь прикупить?\n";
    while (comand != 0)
    {
        int comand;
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
            shop_money = WEAPON_money_IRON_CLUB;
            shop_name = "Железная Дубинка";
            shop_dmg_item = WEAPON_dmg_IRON_CLUB;
            shop = 1; break;
        case SMITH_COMMAND_STEEL_SWORD:
            shop_money = WEAPON_money_STEEL_SWORD;
            shop_name = "Стальной Меч";
            shop_dmg_item = WEAPON_dmg_STEEL_SWORD;
            shop = 1; break;
        case SMITH_COMMAND_LEATHER_ARMOR:
            shop_money = ARMOR_money_LEATHER_ARMOR;
            shop_name = "Кожаная броня";
            shop_hp_item = ARMOR_hp_LEATHER_ARMOR;
            shop = 2; break;
        case SMITH_COMMAND_IRON_ARMOR:
            shop_money = ARMOR_money_IRON_ARMOR;
            shop_name = "Железная броня./n";
            shop_hp_item = ARMOR_hp_IRON_ARMOR;
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

//Подбор
void recruitment_of_the_enemy(int &enemy_hp, int &enemy_dmg, int &enemy_exp, int &enemy_money, int &enemy , int &lvl_number)
{
    enemy = rand() % 100;
    if (enemy >= 0 && enemy <= 6)
    {
        std::cout << "Вы наткнулись на лешого." << std::endl;
        enemy_hp = ENEMIES_WOOD_GOBLIN_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_WOOD_GOBLIN_dmg;
        enemy_exp = ENEMIES_WOOD_GOBLIN_exp;
        enemy_money = ENEMIES_WOOD_GOBLIN_money;
    }
    else if (enemy >= 7 && enemy <= 20)
    {
        std::cout << "С дерева спрыгнул эльф." << std::endl;
        enemy_hp = ENEMIES_ELF_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_ELF_dmg;
        enemy_exp = ENEMIES_ELF_exp;
        enemy_money = ENEMIES_ELF_money;
    }
    else if (enemy >= 21 && enemy <= 41)
    {
        std::cout << "Огр хочет сделать из вас суп." << std::endl;
        enemy_hp = ENEMIES_OGR_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_OGR_dmg;
        enemy_exp = ENEMIES_OGR_exp;
        enemy_money = ENEMIES_OGR_money;
    }
    else if (enemy >= 42 && enemy <= 68)
    {
        std::cout << "На вас напал дикий пес ." << std::endl;
        enemy_hp = ENEMIES_WILD_DOG_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_WILD_DOG_dmg;
        enemy_exp = ENEMIES_WILD_DOG_exp;
        enemy_money = ENEMIES_WILD_DOG_money;
    }
    else if (enemy >= 69 && enemy <= 92)
    {
        std::cout << "Из куста выпрыгнул слизень." << std::endl;
        enemy_hp = ENEMIES_SLIZEN_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_SLIZEN_dmg;
        enemy_exp = ENEMIES_SLIZEN_exp;
        enemy_money = ENEMIES_SLIZEN_money;
    }
    else if (enemy >= 93 && enemy <=99)
        std::cout << "Противник не найден.\n\n";
    }

//Начальная инициализация
void specifications(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg, std::string weapon_name, std::string armor_name, std::string shop_name, int& lvl_number, int& exp, int& comand, int& hp, int& hp_item, int& goddamn, int& dmg, int& dmg_item, int& enemy, int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& money, int& shop, int& shop_money, int& enemy_money, int& shop_hp_item, int& shop_dmg_item)
{
    lvl_number = 0, exp = 0, comand; //Разное
    hp = 100, hp_item = 0, goddamn = 0; //Жизнь
    dmg, dmg_item = 0;  //Урон
    enemy = 0, enemy_hp = 0, enemy_dmg = 0, enemy_exp = 0; //Враг
    money = 0, shop = 0, shop_money = 0, enemy_money = 0, shop_hp_item = 0, shop_dmg_item = 0; //Магазин

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