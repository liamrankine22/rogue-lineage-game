#ifndef CARD_HPP
#define CARD_HPP

#include <raylib.h>
#include <character.hpp>

class card
{
    private:
        character* actor;
        Texture2D image;
        std::string name;
        std::string description;
        int health;
        int mana;
        int agility;
    public:
        card(character* actor);
        character* get_actor();
        Texture2D get_image();
        std::string get_name();
        std::string get_description();
        int get_health();
        int get_mana();
        int get_agility();
        void set_actor(character* actor);
        void set_image(Texture2D image);
        void set_name(std::string name);
        void set_description(std::string description);
        void set_health(int health);
        void set_mana(int mana);
        void set_agility(int agility);
        void draw_card(int x, int y, int width, int height);
};

#endif