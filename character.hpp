#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <race.hpp>
#include <item.hpp>
#include <spell.hpp>
#include <ability.hpp>
#include <vector>
#include <raylib.h>

class character 
{
    private:
        std::string name;
        std::string description;
        race* character_race;
        Texture2D image;
        int health;
        int mana;
        int num_snapped_spells;
        int agility;
        int innate_dmg_reduction;
        bool tomeless;
        bool has_mana;
        std::vector<spell*> spells;
        std::vector<item*> inventory;
        std::vector<ability*> abilities;
    public:
        character();
        character(std::string name, std::string description, race *character_race, Texture2D image);
        std::string get_name();
        std::string get_description();
        race* get_race();
        Texture2D get_image();
        int get_health();
        int get_mana();
        int get_num_snapped_spells();
        int get_agility();
        int get_innate_dmg_reduction();
        bool get_tomeless();
        bool get_has_mana();
        std::vector<spell*> get_spells();
        std::vector<item*> get_inventory();
        std::vector<ability*> get_abilities();
        void set_name(std::string name);
        void set_description(std::string description);
        void set_race(race* new_race);
        void set_image(Texture2D image);
        void set_health(int health);
        void set_mana(int mana);
        void set_num_snapped_spells(int num_snapped_spells);
        void set_agility(int agility);
        void set_innate_dmg_reduction(int innate_dmg_reduction);
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