#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <vector>


class Pokemon {

private:
    std::string name;
    std::string type;
    int level;
    int hp;
    int attackPower;
    int id;
    static int nextID;

public:
    Pokemon(std::string name, std::string type, int level, int hp, int attackPower);
    std::string getName() const;
    void setName(std::string name);
    std::string getType();
    void setType(std::string type);
    int getLevel();
    void setLevel(int level);
    int getHp();
    void setHp(int hp);
    int getAttackPower();
    void setAttackPower(int attackPower);
    int getId();
    virtual void attack(Pokemon& p);
};

#endif
