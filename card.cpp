#include <raylib.h>
#include <string.h>
#include <card.hpp>
#include <character.hpp>
#include <raylib.h>

//Constructor
card::card(character* actor)
{
    this->actor = actor;
    this->image = actor->get_image();
    this->name = actor->get_name();
    this->description = actor->get_description();
    this->health = actor->get_health();
    this->mana = actor->get_mana();
    this->agility = actor->get_agility();
}

//Getters
character* card::get_actor(){ return actor;}
Texture2D card::get_image(){ return image; }
int card::get_health(){ return health; }
int card::get_mana(){ return mana; }
int card::get_agility(){ return agility; }

//Setters
void card::set_actor(character* actor){ this->actor = actor; }
void card::set_image(Texture2D image){ this->image = image; }
void card::set_name(std::string name){ this->name = name; }
void card::set_description(std::string description){ this->description = description; }
void card::set_health(int health){ this->health = health; }
void card::set_mana(int mana){ this->mana = mana; }
void card::set_agility(int agility){ this->agility = agility; }

//Draws the card
void card::draw_card(int x, int y, int width, int height)
{
    DrawRectangle(x, y, width, height, WHITE);
    DrawTexture(image, x + 10, y + 10, WHITE);
    DrawText(name.c_str(), x + 60, y + 135, 15, BLACK);
    DrawText(description.c_str(), x + 10, y + 155, 7, BLACK);
    DrawText(("Health: " + std::to_string(health)).c_str(), x + 10, y + 165, 7, BLACK);
    DrawText(("Mana: " + std::to_string(mana)).c_str(), x + 10, y + 175, 7, BLACK);
    DrawText(("Agility: " + std::to_string(agility)).c_str(), x + 10, y + 185, 7, BLACK);
}