#ifndef POKEMONDATABASE_H
#define POKEMONDATABASE_H

#include <string>
#include <vector>
#include "fireType.h"
#include "waterType.h"
#include "grassType.h"
#include "electricType.h"
#include "groundType.h"

struct PokemonTemplate {
    std::string name;
    std::string type;
    int level;
    int hp;
    int attackPower;
};

// Return a list of all predefined Pokémon templates
inline std::vector<PokemonTemplate> getPokemonTemplates() {
    return {
        {"Charmander", "Fire", 10, 30, 8},
        {"Charmeleon", "Fire", 25, 50, 15},
        {"Charizard", "Fire", 50, 90, 25},
        {"Squirtle", "Water", 10, 30, 8},
        {"Wartortle", "Water", 25, 50, 15},
        {"Blastoise", "Water", 50, 80, 28},
        {"Bulbasaur", "Grass", 10, 32, 9},
        {"Ivysaur", "Grass", 25, 50, 15},
        {"Venusaur", "Grass", 50, 85, 21},
        {"Pikachu", "Electric", 15, 37, 11},
        {"Raichu", "Electric", 40, 70, 23},
        {"Diglett", "Ground", 10, 25, 12},
        {"Onix", "Ground", 40, 100, 18},
    };
}

// Create a real Pokémon object from a template
inline Pokemon* createFromTemplate(const PokemonTemplate& t) {
    if (t.type == "Fire") return new FireType(t.name, t.level, t.hp, t.attackPower);
    if (t.type == "Water") return new WaterType(t.name, t.level, t.hp, t.attackPower);
    if (t.type == "Grass") return new GrassType(t.name, t.level, t.hp, t.attackPower);
    if (t.type == "Electric") return new ElectricType(t.name, t.level, t.hp, t.attackPower);
    if (t.type == "Ground") return new GroundType(t.name, t.level, t.hp, t.attackPower);
    return nullptr;
}

#endif

