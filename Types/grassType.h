#ifndef GRASSTYPE_H
#define GRASSTYPE_H
#include <iostream>
#include <string>
#include "pokemon.h"


class GrassType : public Pokemon {
    private:
        std::string weakness;
    public:
        GrassType(std::string name, int level, int hp, int attackPower);
        void attack(Pokemon& p);
};

#endif
