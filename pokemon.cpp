#include "pokemon.h"       // Include the header file where the Pokemon class is declared
#include <iostream>

using namespace std;

// Initialize the static variable 'nextID' which keeps track of unique Pokémon IDs
int Pokemon::nextID = 1;

// Constructor: creates a new Pokémon with given name, type, level, HP, and attack power
// Also assigns a unique ID to each Pokémon using the static 'nextID'
Pokemon::Pokemon(string name, string type, int level, int hp, int attackPower)
    : name(name), type(type), level(level), hp(hp), attackPower(attackPower) {
    id = nextID++;  // Auto-incrementing ID for each new Pokémon
}

// Getter for name - returns the name of the Pokémon
string Pokemon::getName() const {
    return name;
}

// Setter for name - updates the Pokémon's name
void Pokemon::setName(string name) {
    this->name = name;
}

// Getter for type - returns the Pokémon's type (e.g., Fire, Water)
string Pokemon::getType() {
    return type;
}

// Setter for type - sets the type of the Pokémon
void Pokemon::setType(string type) {
    this->type = type;
}

// Getter for level - returns the Pokémon's current level
int Pokemon::getLevel() {
    return level;
}

// Setter for level - updates the Pokémon's level
void Pokemon::setLevel(int level) {
    this->level = level;
}

// Getter for HP - returns current health points
int Pokemon::getHp() {
    return hp;
}

// Setter for HP - sets the Pokémon's HP to a new value
void Pokemon::setHp(int hp) {
    this->hp = hp;
}

// Getter for attack power - returns the Pokémon's attack strength
int Pokemon::getAttackPower() {
    return attackPower;
}

// Setter for attack power - updates the Pokémon's attack strength
void Pokemon::setAttackPower(int attackPower) {
    this->attackPower = attackPower;
}

// Getter for ID - returns the unique ID assigned to this Pokémon
int Pokemon::getId() {
    return id;
}

// Attack function - prints an attack message and reduces the target Pokémon's HP
void Pokemon::attack(Pokemon& p) {
    cout << name << " attacks " << p.getName() << " dealing " << attackPower << " damage!" << endl;
    // Reduce the target Pokémon's HP by this Pokémon's attack power
    p.setHp(p.getHp() - attackPower);
}

