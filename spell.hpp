#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>

class spell 
{
    private:
        std::string name;
        std::string description;
        std::string stat_affect;
        int damage;
        int mana_cost;
    public:
        spell();
        spell(std::string name, std::string description, std::string stat_affect, int damage, int mana, bool snapped);
        std::string get_name();
        std::string get_description();
        std::string get_stat_affect();
        int get_damage();
        int get_mana_cost();
        void set_name(std::string name);
        void set_description(std::string description);
        void set_stat_affect(std::string stat_affect);
        void set_damage(int damage);
        void set_mana_cost(int mana);
};

#endif