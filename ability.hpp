#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <string>

class ability //ABILITIES SHOULD BE PUT INTO MEMORY AND POINTED TO BY THE PLAYER CLASS 
{
    private:
        std::string name;
        std::string description;
        std::string type; //Passive or Active
        std::string effect; //What the ability does
        int cost; //Cost of the ability
        int damage; //Damage of the ability (damage to health as negative int or healing as positive int)
        int cooldown; //Cooldown of the ability
    public:
        ability();
        ability(std::string name, std::string description, std::string type, std::string effect, int damage, int cooldown);
        void set_name(std::string name);
        void set_description(std::string description);
        void set_type(std::string type);
        void set_effect(std::string effect);
        void set_cost(int cost);
        void set_damage(int damage);
        void set_cooldown(int cooldown);
        std::string get_name();
        std::string get_description();
        std::string get_type();
        std::string get_effect();
        int get_cost();
        int get_damage();
        int get_cooldown();
};

#endif