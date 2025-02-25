#include <objectinit.hpp>
#include <string.h>

objectinit::objectinit()
{
    //Initialize all spells, abilities, characters and items here
}
ability* objectinit::getAbility(std::string name){ return &abilities[name]; }
item* objectinit::getItem(std::string name){ return &items[name]; }
spell* objectinit::getSpell(std::string name){ return &spells[name]; }
character* objectinit::getCharacter(std::string name)
{ 
    auto it = characters.find(name);
    if (it != characters.end()) 
    {
        return &it->second;  // If found, return the character
    }
    return nullptr;  // If not found, return nullptr
}
void objectinit::add_ability(std::string name, ability ab){ abilities[name] = ab; }
void objectinit::add_item(std::string name, item it){ items[name] = it; }
void objectinit::add_spell(std::string name, spell sp){ spells[name] = sp; }
void objectinit::add_character(std::string name, character ch){ characters[name] = ch; }