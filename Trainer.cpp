#include <iostream>
#include <fstream>
#include "Trainer.h"

using namespace std;

// Constructor – initializes the trainer with a name and 0 badges
Trainer::Trainer(string n) {
    name = n;
    badgeCount = 0;
}

// Destructor – deletes all dynamically allocated Pokémon and clears the team
Trainer::~Trainer() {
    for(auto p : Team) {
        delete p;
    }
    Team.clear();
}

// Getter for trainer's name
string Trainer::getName() const {
    return name;
}

// Returns a reference to the trainer's team vector (used to directly access Pokémon)
vector<Pokemon*>& Trainer::getTeam() {
    return Team;
}

// Returns how many Pokémon are currently in the trainer’s team
int Trainer::getTeamSize() const {
    return Team.size();
}

// Adds a Pokémon to the trainer’s team (if less than 6)
bool Trainer::addPokemon(Pokemon* p) {
    if(Team.size() < 6) {
        Team.push_back(p);
        return true;
    } else {
        cout << "Team is full! Cannot add more than 6 Pokemon. \n";
        return false;
    }
}

// Removes a Pokémon by index and frees its memory
void Trainer::removePokemon(int index) {
    if(index >= 0 && index < Team.size()) {
        delete Team[index];
        Team.erase(Team.begin() + index);
    } else {
        cout << "Invalid index. \n";
    }
}

// Displays each Pokémon on the trainer’s team with basic stats
void Trainer::viewTeam() {
    cout << "\n" << name << "'s Team:\n";
    for(int i = 0; i < Team.size(); i++) {
        cout << i + 1 << ". " << Team[i]->getName()
             << " (Type: " << Team[i]->getType()
             << ", Level: " << Team[i]->getLevel()
             << ", HP: " << Team[i]->getHp()
             << ", ATK: " << Team[i]->getAttackPower()
             << ")\n";
    }
    if(Team.empty()) {
        cout << "No Pokemon in the team.\n";
    }
}

// Displays general trainer information (name, badge count, team size)
void Trainer::viewStats() {
    cout << "\nTrainer: " << name << "\n";
    cout << "Badges: " << badgeCount << "\n";
    cout << "Team Size: " << Team.size() << "\n";
}

// Saves the current team to a text file (used for persistence)
void Trainer::saveTeam(std::string filename) {
    std::ofstream outFile(filename); // Open file for writing
    if (!outFile) {
        std::cout << "Error opening file for writing.\n";
        return;
    }

    // Write each Pokémon's data in space-separated format
    for (auto p : Team) {
        outFile << p->getName() << " "
                << p->getType() << " "
                << p->getLevel() << " "
                << p->getHp() << " "
                << p->getAttackPower() << "\n";
    }

    outFile.close();
    std::cout << "Team saved to " << filename << "\n";
}

// Loads a team from a text file and replaces the current team
void Trainer::loadTeam(std::string filename) {
    std::ifstream file(filename); // Open file for reading
    if (!file.is_open()) {
        std::cerr << "Could not open file for loading!" << std::endl;
        return;
    }

    // Clear existing team
    for (Pokemon* p : Team)
        delete p;
    Team.clear();

    // Read values for each Pokémon from the file
    string pname, ptype;
    int plevel, php, pattack;

    while (file >> pname >> ptype >> plevel >> php >> pattack) {
        Pokemon* newPoke = new Pokemon(pname, ptype, plevel, php, pattack);
        Team.push_back(newPoke);
    }

    file.close();
}

