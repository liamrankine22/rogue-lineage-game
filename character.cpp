#include <character.hpp>

#include <string>
#include <race.hpp>
#include <item.hpp>
#include <spell.hpp>
#include <ability.hpp>
#include <vector>
#include <raylib.h>

//Constructor
character::character()
{
    this->name = "default";
    this->description = "default";
    this->character_race = nullptr;
    this->image = LoadTextureFromImage(LoadImage("imgs/castellan_shinobi.png"));
    this->health = 0;
    this->mana = 0;
    this->num_snapped_spells = 0;
}
character::character(std::string name, std::string description, race* character_race, Texture2D image)
{
    this->name = name;
    this->description = description;
    this->character_race = character_race;
    this->image = image;
    this->health = character_race->get_base_health();
    this->mana = 0;
    this->num_snapped_spells = 0;
    this->agility = character_race->get_base_agility();
    this->innate_dmg_reduction = character_race->get_innate_dmg_reduction();
    this->tomeless = character_race->get_tomeless();
    this->has_mana = character_race->get_has_mana();
    for (int i = 0; i < character_race->get_abilities().size(); i++)
    {
        this->abilities.push_back(character_race->get_abilities()[i]);
    }
}

//Getters
std::string character::get_name(){ return name; }
std::string character::get_description(){ return description; }
race* character::get_race(){ return character_race; }
Texture2D character::get_image(){ return image; }
int character::get_health(){ return health; }
int character::get_mana(){ return mana; }
int character::get_num_snapped_spells() { return num_snapped_spells; }
int character::get_agility() { return agility; }
int character::get_innate_dmg_reduction() { return innate_dmg_reduction; }
bool character::get_tomeless() { return tomeless; }
bool character::get_has_mana() { return has_mana; }
std::vector<spell*> character::get_spells() { return spells; }
std::vector<item*> character::get_inventory() { return inventory; }
std::vector<ability*> character::get_abilities() { return abilities; }

//Setters
void character::set_name(std::string name) { this->name = name; }
void character::set_description(std::string description) { this->description = description; }
void character::set_race(race* new_race) { this->character_race = new_race; }
void character::set_image(Texture2D image) { this->image = image; }
void character::set_health(int health) { this->health = health; }
void character::set_mana(int mana) { this->mana = mana; }
void character::set_num_snapped_spells(int num_snapped_spells) { this->num_snapped_spells = num_snapped_spells; }
void character::set_agility(int agility) { this->agility = agility; }
void character::set_innate_dmg_reduction(int innate_dmg_reduction) { this->innate_dmg_reduction = innate_dmg_reduction; }
void character::set_tomeless(bool tomeless) { this->tomeless = tomeless; }
void character::set_has_mana(bool has_mana) { this->has_mana = has_mana; }

//Adders/Removers
void character::add_spell(spell* spell) { spells.push_back(spell); }
void character::add_item(item* item) { inventory.push_back(item); }
void character::add_ability(ability* ability) { abilities.push_back(ability); }
void character::remove_spell(std::string spell_name)
{
    for (int i = 0; i < spells.size(); i++)
    {
        if (spells[i]->get_name() == spell_name)
        {
            spells.erase(spells.begin() + i);
            break;
        }
    }
}
void character::remove_item(std::string item_name)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i]->get_name() == item_name)
        {
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}
void character::remove_ability(std::string ability_name)
{
    for (int i = 0; i < abilities.size(); i++)
    {
        if (abilities[i]->get_name() == ability_name)
        {
            abilities.erase(abilities.begin() + i);
            break;
        }
    }
}