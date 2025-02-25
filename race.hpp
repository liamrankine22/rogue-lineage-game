#ifndef RACE_HPP
#define RACE_HPP

#include <string>
#include <vector>
#include <item.hpp>
#include <spell.hpp>
#include <ability.hpp>

class race //ALL RACES INITIALIZED LIKE ABILITIES AND POINTED TO BY THE PLAYER CLASS
{
    private:
        std::string name;
        std::string description;
        int base_health;
        int base_mana_charge_speed;
        int max_snapped_spells;
        int innate_dmg_reduction;
        int base_agility;
        bool spawn_tomeless;
        bool spawn_mana;
        std::vector<spell*> spells;
        std::vector<item*> inventory;
        std::vector<ability*> abilities;
    public:
        //TEMPORARY CONSTRUCTOR BELOW FOR TESTING
        race(std::string name, std::string description, int base_health, int base_mana_charge_speed, int max_snapped_spells, int innate_dmg_reduction, int base_agility, bool spawn_tomeless, bool spawn_mana, std::vector<spell*> spells, std::vector<item*> inventory, std::vector<ability*> abilities);
        std::string get_name();
        std::string get_description();
        int get_base_health();
        int get_base_mana_charge_speed();
        int get_max_snapped_spells();
        int get_base_agility();
        int get_innate_dmg_reduction();
        bool get_tomeless();
        bool get_has_mana();
        std::vector<spell*> get_spells();
        std::vector<item*> get_inventory();
        std::vector<ability*> get_abilities();
        void set_name(std::string name);
        void set_description(std::string description);
        void set_base_health(int health);
        void set_base_mana_charge_speed(int mana);
        void set_max_snapped_spells(int max);
        void set_base_agility(int agility);
        void set_innate_dmg_reduction(int dmg_reduction);
        void set_tomeless(bool tomeless);
        void set_has_mana(bool has_mana);
        void add_spell(spell* spell);
        void add_item(item* item);
        void add_ability(ability* ability);
        void remove_spell(std::string spell_name);
        void remove_item(std::string item_name);
        void remove_ability(std::string ability_name);
};

#endif