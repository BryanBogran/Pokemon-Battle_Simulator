#include "battle.h"
#include "PokemonDatabase.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Constructor sets up the battle by assigning trainers and seeding random number generation
Battle::Battle(Trainer* t1, Trainer* t2) {
    Trainer1 = t1;
    Trainer2 = t2;
    currentTurn = 1;
    std::srand(std::time(nullptr)); // Seed RNG
}

// Main loop that drives the battle between two trainers until one side runs out of Pokémon
void Battle::startBattle() {
    cout << "\n================= POKÉMON BATTLE SIMULATOR =================\n\n";
    cout << "Battle Between " << Trainer1->getName() << " and " << Trainer2->getName() << " begins!\n";
    cout << "============================================================\n";

    while (!Trainer1->getTeam().empty() && !Trainer2->getTeam().empty()) {
        simulateTurn(); // Simulate one turn of battle
        currentTurn++;
    }

    cout << "\n============================================================\n";
    if (!Trainer1->getTeam().empty()) {
        cout << "🏆  " << Trainer1->getName() << " Wins the Battle!\n";
    } else {
        cout << "🏆  " << Trainer2->getName() << " Wins the Battle!\n";
    }
    cout << "============================================================\n";
}

// Simulates a single turn where each Pokémon gets a chance to attack
void Battle::simulateTurn() {
    cout << "\n---------------------------- TURN " << currentTurn << " ----------------------------\n";

    Pokemon* p1 = Trainer1->getTeam().front();
    Pokemon* p2 = Trainer2->getTeam().front();

    displayBattleScreen(); // Show HP and names of battling Pokémon

    p1->attack(*p2); // Trainer 1's Pokémon attacks
    if (isFainted(p2)) {
        cout << "💀 " << p2->getName() << " fainted!\n";
        Trainer2->removePokemon(0); // Remove fainted Pokémon
        return;
    }

    p2->attack(*p1); // Trainer 2's Pokémon attacks
    if (isFainted(p1)) {
        cout << "💀 " << p1->getName() << " fainted!\n";
        Trainer1->removePokemon(0);
    }
}

// Returns damage amount with slight randomness to keep gameplay dynamic
int Battle::calculateDamage(Pokemon* attacker, Pokemon* defender) {
    int baseDamage = attacker->getAttackPower();
    int randomFactor = std::rand() % 5;
    return std::max(1, baseDamage - randomFactor);
}

// Returns true if Pokémon has 0 or less HP
bool Battle::isFainted(Pokemon* p) {
    return p->getHp() <= 0;
}

// Nicely formatted display of both Pokémon currently battling
void Battle::displayBattleScreen() {
    Pokemon* p1 = Trainer1->getTeam().front();
    Pokemon* p2 = Trainer2->getTeam().front();

    cout << left << setw(20) << Trainer1->getName() + "'s " + p1->getName()
         << " (HP: " << setw(3) << p1->getHp() << ")  vs  "
         << right << setw(20) << Trainer2->getName() + "'s " + p2->getName()
         << " (HP: " << p2->getHp() << ")\n\n";
}

// Generates 6 random opponent Pokémon using template list with no duplicates
void Battle::generateOpponentTeam(Trainer* t) {
    auto templates = getPokemonTemplates();
    std::vector<int> usedIndices;

    while (usedIndices.size() < 6) {
        int index = rand() % templates.size();
        if (std::find(usedIndices.begin(), usedIndices.end(), index) == usedIndices.end()) {
            usedIndices.push_back(index);
            Pokemon* p = createFromTemplate(templates[index]);
            t->addPokemon(p);
            std::cout << p->getName() << " added to " << t->getName() << "'s team.\n";
        }
    }

    std::cout << t->getName() << "'s opponent team has been generated.\n";
}
