#include "electricType.h"
#include <iostream>

using namespace std;

ElectricType::ElectricType(string name, int level, int hp, int attackPower) : Pokemon(name, "Electric", level, hp, attackPower) {
    weakness = "Ground"; //weakness of Electrcity is Ground Type
}

void ElectricType::attack(Pokemon& p) {
    int damage = getAttackPower();

    if (p.getType() == weakness) { 
        damage /= 2; //Electric Type will do only half damage against Ground Pokemon
        cout << "It's not very effective..." << endl;
    }
    else if (p.getType() == "Water") {
        damage *= 2; //Electric type Pokemon will do double damage against water Pokemon
        cout << "It's super effective! ";
    }
    else {
        //normal Damage
    }
    
    cout << getName() << " attacks " << p.getName() << " dealing " << damage << " damage!\n";

    p.setHp(p.getHp() - damage);
    cout << p.getName() << "'s HP is now " << p.getHp() << endl;
}

