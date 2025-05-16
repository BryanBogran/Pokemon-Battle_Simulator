#ifndef FIRETYPE_H
#define FIRETYPE_H
#include <iostream>
#include <string>
#include "pokemon.h"


class FireType : public Pokemon {
    private:
        std::string weakness;
    public:
        FireType(std::string name, int level, int hp, int attackPower);
        void attack(Pokemon& p) override;
};

#endif
