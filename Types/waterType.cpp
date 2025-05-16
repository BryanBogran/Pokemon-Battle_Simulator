#include "waterType.h"
#include <iostream>

using namespace std;

WaterType::WaterType(string name, int level, int hp, int attackPower) : Pokemon(name, "Water", level, hp, attackPower) {
    weakness = "Electric";
}

void WaterType::attack(Pokemon& p) {
    int damage = getAttackPower();

    if (p.getType() == weakness) {
        damage /= 2;
        cout << "It's not very effective..." << endl;
    }
    else if (p.getType() == "Fire") {
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

