#include "fireType.h"   // Include the FireType header, which inherits from the base Pokemon class
#include <iostream>

using namespace std;

// FireType constructor – initializes a Fire-type Pokémon with name, level, HP, and attackPower
// Also sets its weakness to Water
FireType::FireType(string name, int level, int hp, int attackPower)
    : Pokemon(name, "Fire", level, hp, attackPower) {
    weakness = "Water"; // Fire is weak to Water
}

// Override of the virtual attack function from the base class
// This includes type-effectiveness logic specific to Fire-type Pokémon
void FireType::attack(Pokemon& p) {
    int damage = getAttackPower(); // Start with this Pokémon's attack power

    // Check for weakness (Fire is weak to Water — deal half damage)
    if (p.getType() == weakness) {
        damage /= 2;
        cout << "It's not very effective..." << endl;
    }

    // Check for type advantage (Fire is strong against Grass — deal double damage)
    else if (p.getType() == "Grass") {
        damage *= 2;
        cout << "It's super effective! ";
    }

    // No special modifier, just normal damage
    else {
        // Normal damage output
    }

    // Display attack info
    cout << getName() << " attacks " << p.getName()
         << " dealing " << damage << " damage!\n";

    // Reduce the target Pokémon's HP by calculated damage
    p.setHp(p.getHp() - damage);

    // Show remaining HP of the target Pokémon
    cout << p.getName() << "'s HP is now " << p.getHp() << endl;
}

