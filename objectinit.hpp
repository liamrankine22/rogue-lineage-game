#ifndef OBJECTINIT_HPP
#define OBJECTINIT_HPP

#include <unordered_map>
#include <ability.hpp>
#include <item.hpp>
#include <spell.hpp>
#include <character.hpp>

class objectinit //Initalizes all abilities, items, spells, etc... into memory
{
    private:
        std::unordered_map<std::string, ability> abilities;
        std::unordered_map<std::string, item> items;
        std::unordered_map<std::string, spell> spells;
        std::unordered_map<std::string, character> characters;
    public:
        objectinit();
        ability* getAbility(std::string name);
        item* getItem(std::string name);
        spell* getSpell(std::string name);
        character* getCharacter(std::string name);
        void add_ability(std::string name, ability ab);
        void add_item(std::string name, item it);
        void add_spell(std::string name, spell sp);
        void add_character(std::string name, character ch);
};

#endif