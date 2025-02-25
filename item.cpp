#include "item.hpp"

//Constructor
item::item()
{
    this->name = "";
    this->description = "";
    this->value = 0;
    this->sellable = false;
    this->consumable = false;
    this->equipable = false;
    this->num_carried = 0;
}
item::item(std::string name, std::string description, int value, bool sellable, int weight, bool consumable, bool equipable, int num_carried)
{
    this->name = name;
    this->description = description;
    this->value = value;
    this->sellable = sellable;
    this->consumable = consumable;
    this->equipable = equipable;
    this->num_carried = num_carried;
}

//Getters
std::string item::get_name() { return name; }
std::string item::get_description() { return description; }
int item::get_value() { return value; }
bool item::get_sellable() { return sellable; }
bool item::get_consumable() { return consumable; }
bool item::get_equipable() { return equipable; }
int item::get_num_carried() { return num_carried; }
std::vector<std::string> item::get_effect_type() { return effect_type; }
std::vector<int> item::get_effect_value() { return effect_value; }

//Setters
void item::set_name(std::string name) { this->name = name; }
void item::set_description(std::string description) { this->description = description; }
void item::set_value(int value) { this->value = value; }
void item::set_sellable(bool sellable) { this->sellable = sellable; }
void item::set_consumable(bool consumable) { this->consumable = consumable; }
void item::set_equipable(bool equipable) { this->equipable = equipable; }
void item::set_num_carried(int num) { this->num_carried = num; }
