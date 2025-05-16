#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>
#include <vector>
#include "pokemon.h"


class Trainer {

private:
    std::string name;
    int badgeCount;
    std::vector <Pokemon*> Team;

public:
    Trainer(std::string n);
    ~Trainer();
    std::string getName() const;
    std::vector<Pokemon*>& getTeam();
    int getTeamSize() const;
    bool addPokemon(Pokemon* p);
    void removePokemon(int index);
    void viewTeam();
    void viewStats();
    void saveTeam(std::string filename);
    void loadTeam(std::string filename);
};

#endif
