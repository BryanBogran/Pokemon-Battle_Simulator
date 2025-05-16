#include "grassType.h"
#include <iostream>

using namespace std;

GrassType::GrassType(string name, int level, int hp, int attackPower) : Pokemon(name, "Grass", level, hp, attackPower) {
    weakness = "Fire";
}

void GrassType::attack(Pokemon& p) {
    int damage = getAttackPower();

    if (p.getType() == weakness) {
        damage /= 2;
        cout << "It's not very effective..." << endl;
    }
    else if (p.getType() == "Ground") {
        damage *= 2;
        cout << "It's super effective! ";
    }
    else {
        //normal Damage
    }
    
    cout << getName() << " attacks " << p.getName() << " dealing " << damage << " damage!\n";

    p.setHp(p.getHp() - damage);
    cout << p.getName() << "'s HP is now " << p.getHp() << endl;
}

