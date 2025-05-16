#ifndef ELECTRICTYPE_H
#define ELECTRICTYPE_H

#include <iostream>
#include <string>
#include "pokemon.h"


class ElectricType : public Pokemon {
    private:
        std::string weakness;
    public:
        ElectricType(std::string name, int level, int hp, int attackPower);
        void attack(Pokemon& p) override;
};

#endif
