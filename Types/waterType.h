#ifndef WATERTYPE_H
#define WATERTYPE_H

#include <iostream>
#include <string>
#include "pokemon.h"


class WaterType : public Pokemon {
    private:
        std::string weakness;
    public:
        WaterType(std::string name, int level, int hp, int attackPower);
        void attack(Pokemon& p);
};

#endif
