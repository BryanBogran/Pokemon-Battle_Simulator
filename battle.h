#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <string>
#include <vector>
#include "Trainer.h"
#include "pokemon.h"


class Battle {
    private:
        Trainer* Trainer1;
        Trainer* Trainer2;
        int currentTurn;
    public:
        Battle(Trainer* t1, Trainer* t2);
        void startBattle();
        void simulateTurn();
        int calculateDamage(Pokemon* attacker, Pokemon* defender);
        bool isFainted(Pokemon* p);
        void displayBattleScreen();
        void generateOpponentTeam(Trainer* t);
};

#endif
