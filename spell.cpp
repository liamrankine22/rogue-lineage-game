#include "spell.hpp"
#include <string>


//Constructor
spell::spell()
{
    this->name = "default";
    this->description = "default";
    this->stat_affect = "null";
    this->damage = 0;
    this->mana_cost = 0;
}
spell::spell(std::string name, std::string description, std::string stat_affect, int damage, int mana, bool snapped) {
            this->name = name;
            this->description = description;
            this->stat_affect = stat_affect;
            this->damage = damage;
            this->mana_cost = mana;
}

//Getters
std::string spell::get_name() { return name; }
std::string spell::get_description() { return description; }
std::string spell::get_stat_affect() { return stat_affect; }
int spell::get_damage() { return damage; }
int spell::get_mana_cost() { return mana_cost; }

//Setters
void spell::set_name(std::string name) { this->name = name; }
void spell::set_description(std::string description) { this->description = description; }
void spell::set_stat_affect(std::string stat_affect) { this->stat_affect = stat_affect; }
void spell::set_damage(int damage) { this->damage = damage; }
void spell::set_mana_cost(int mana) { this->mana_cost = mana; }