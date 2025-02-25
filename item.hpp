#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <vector>

class item //ITEMS SHOULD BE PUT INTO MEMORY BY OBJECTINIT AND POINTED TO BY THE PLAYER CLASS 
{
    private:
        std::string name;
        std::string description;
        int value;
        bool sellable;
        bool consumable;
        bool equipable;
        int num_carried;
        std::vector<std::string> effect_type;
        std::vector<int> effect_value;
    public:
        item();
        item(std::string name, std::string description, int value, bool sellable, int weight, bool consumable, bool equipable, int num_carried);
        std::string get_name();
        std::string get_description();
        int get_value();
        bool get_sellable();
        bool get_consumable();
        bool get_equipable();   
        int get_num_carried();
        std::vector<std::string> get_effect_type();
        std::vector<int> get_effect_value();
        void set_name(std::string name);
        void set_description(std::string description);
        void set_value(int value);
        void set_sellable(bool sellable);
        void set_consumable(bool consumable);
        void set_equipable(bool equipable);
        void set_num_carried(int num);
};

#endif