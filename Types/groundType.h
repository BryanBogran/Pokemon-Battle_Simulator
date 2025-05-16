#ifndef GROUNDTYPE_H
#define GROUNDTYPE_H

#include <iostream>
#include <string>
#include "pokemon.h"


class GroundType : public Pokemon {
    private:
        std::string weakness;
    public:
        GroundType(std::string name, int level, int hp, int attackPower);
        void attack(Pokemon& p) override;
};

#endif
