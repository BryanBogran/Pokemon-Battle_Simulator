#include "groundType.h"
#include <iostream>

using namespace std;

GroundType::GroundType(string name, int level, int hp, int attackPower) : Pokemon(name, "Ground", level, hp, attackPower) {
    weakness = "Grass";
}

void GroundType::attack(Pokemon& p) {
    int damage = getAttackPower();

    if (p.getType() == weakness) {
        damage /= 2;
        cout << "It's not very effective..." << endl;
    }
    else if (p.getType() == "Electric") {
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

