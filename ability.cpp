#include "ability.hpp"

// Constructor definition
ability::ability()
{
    this->name = "";
    this->description = "";
    this->type = "";
    this->effect = "";
    this->cost = 0;
    this->damage = 0;
    this->cooldown = 0;
}
ability::ability(std::string name, std::string description, std::string type, std::string effect, int damage, int cooldown)
{
    this->name = name;
    this->description = description;
    this->type = type;
    this->effect = effect;
    this->cost = cost;
    this->damage = damage;
    this->cooldown = cooldown;
}

// Setter methods
void ability::set_name(std::string name) { this->name = name; }
void ability::set_description(std::string description) { this->description = description; }
void ability::set_type(std::string type) { this->type = type; }
void ability::set_effect(std::string effect) { this->effect = effect; }
void ability::set_cost(int cost) { this->cost = cost; }
void ability::set_damage(int damage) { this->damage = damage; }
void ability::set_cooldown(int cooldown) { this->cooldown = cooldown; }

// Getter methods
std::string ability::get_name() { return name; }
std::string ability::get_description() { return description; }
std::string ability::get_type() { return type; }
std::string ability::get_effect() { return effect; }
int ability::get_cost() { return cost; }
int ability::get_damage() { return damage; }
int ability::get_cooldown() { return cooldown; }
