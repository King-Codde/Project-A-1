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
class EnemyAndCo
{
public:
    int enemy_ogr_hp = ENEMIES_OGR_hp;
    int enemy_ogr_dmg = ENEMIES_OGR_dmg;
    int enemy_ogr_exp = ENEMIES_OGR_exp;
    int enemy_ogr_money = ENEMIES_OGR_money;

    int enemy_elf_hp = ENEMIES_ELF_hp;
    int enemy_elf_dmg = ENEMIES_ELF_dmg;
    int enemy_elf_exp = ENEMIES_ELF_exp;
    int enemy_elf_money = ENEMIES_ELF_money;

    int enemy_wood_hp = ENEMIES_WOOD_GOBLIN_hp;
    int enemy_wood_dmg = ENEMIES_WOOD_GOBLIN_dmg;
    int enemy_wood_exp = ENEMIES_WOOD_GOBLIN_exp;
    int enemy_wood_money = ENEMIES_WOOD_GOBLIN_money;

    int enemy_slizen_hp = ENEMIES_SLIZEN_hp;
    int enemy_slizen_dmg = ENEMIES_SLIZEN_dmg;
    int enemy_slizen_exp = ENEMIES_SLIZEN_exp;
    int enemy_slizen_money = ENEMIES_SLIZEN_money;

    int enemy_wild_dog_hp = ENEMIES_WILD_DOG_hp;
    int enemy_wild_dog_dmg = ENEMIES_WILD_DOG_dmg;
    int enemy_wild_dog_exp = ENEMIES_WILD_DOG_exp;
    int enemy_wild_dog_money = ENEMIES_WILD_DOG_money;

};
class wepon_and_armor
{
public:
    int weapon_money_iron_club = WEAPON_money_IRON_CLUB;
    int weapon_dmg_iron_club = WEAPON_dmg_IRON_CLUB;
    int weapon_money_steel_sword = WEAPON_money_STEEL_SWORD;
    int weapon_dmg_steel_sword = WEAPON_dmg_STEEL_SWORD;
    int armor_money_leather_armor = ARMOR_money_LEATHER_ARMOR;
    int armor_hp_leather_armor = ARMOR_hp_LEATHER_ARMOR;
    int armor_money_iron_armor = ARMOR_money_IRON_ARMOR;
    int armor_hp_iron_armor = ARMOR_hp_IRON_ARMOR;
};
