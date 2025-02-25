#include "race.hpp"

race::race(std::string name, std::string description, int base_health, int base_mana_charge_speed, 
           int max_snapped_spells, int innate_dmg_reduction, int base_agility, bool spawn_tomeless, 
           bool spawn_mana, std::vector<spell*> spells, std::vector<item*> inventory, std::vector<ability*> abilities)
{
    this->name = name;
    this->description = description;
    this->base_health = base_health;
    this->base_mana_charge_speed = base_mana_charge_speed;
    this->max_snapped_spells = max_snapped_spells;
    this->innate_dmg_reduction = innate_dmg_reduction;
    this->base_agility = base_agility;
    this->spawn_tomeless = spawn_tomeless;
    this->spawn_mana = spawn_mana;
    this->spells = spells;
    this->inventory = inventory;
    this->abilities = abilities;
}

std::string race::get_name() { return name; }
std::string race::get_description() { return description; }
int race::get_base_health() { return base_health; }
int race::get_base_mana_charge_speed() { return base_mana_charge_speed; }
int race::get_max_snapped_spells() { return max_snapped_spells; }
int race::get_base_agility() { return base_agility; }
int race::get_innate_dmg_reduction() { return innate_dmg_reduction; }
bool race::get_tomeless() { return spawn_tomeless; }
bool race::get_has_mana() { return spawn_mana; }
std::vector<spell*> race::get_spells() { return spells; }
std::vector<item*> race::get_inventory() { return inventory; }
std::vector<ability*> race::get_abilities() { return abilities; }

void race::set_name(std::string name) { this->name = name; }
void race::set_description(std::string description) { this->description = description; }
void race::set_base_health(int health) { this->base_health = health; }
void race::set_base_mana_charge_speed(int mana) { this->base_mana_charge_speed = mana; }
void race::set_max_snapped_spells(int max) { this->max_snapped_spells = max; }
void race::set_base_agility(int agility) { this->base_agility = agility; }
void race::set_innate_dmg_reduction(int dmg_reduction) { this->innate_dmg_reduction = dmg_reduction; }
void race::set_tomeless(bool tomeless) { this->spawn_tomeless = tomeless; }
void race::set_has_mana(bool has_mana) { this->spawn_mana = has_mana; }

void race::add_spell(spell* spell) { spells.push_back(spell); }
void race::add_item(item* item) { inventory.push_back(item); }
void race::add_ability(ability* ability) { abilities.push_back(ability); }

void race::remove_spell(std::string spell_name)
{
    for (auto it = spells.begin(); it != spells.end(); ++it)
    {
        if ((*it)->get_name() == spell_name)
        {
            spells.erase(it);
            break;
        }
    }
}

void race::remove_item(std::string item_name)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if ((*it)->get_name() == item_name)
        {
            inventory.erase(it);
            break;
        }
    }
}

void race::remove_ability(std::string ability_name)
{
    for (auto it = abilities.begin(); it != abilities.end(); ++it)
    {
        if ((*it)->get_name() == ability_name)
        {
            abilities.erase(it);
            break;
        }
    }
}