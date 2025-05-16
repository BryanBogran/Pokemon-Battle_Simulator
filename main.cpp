#include <iostream>
#include <string>
#include "PokemonDatabase.h" // Contains a database of predefined Pokémon templates
#include "Trainer.h"         // Handles player info and their Pokémon team
//#include "fireType.h"        // Derived Pokémon class for Fire type
//#include "waterType.h"       // Derived Pokémon class for Water type
//#include "grassType.h"       // Derived Pokémon class for Grass type
//#include "electricType.h"    // Derived Pokémon class for Electric type
//#include "groundType.h"      // Derived Pokémon class for Ground type
#include "battle.h"          // Manages turn-based battles between Trainers

using namespace std;

// Function to let the player create a custom Pokémon by typing in all the details
Pokemon* createPokemon() {
    string name, type;
    int level, hp, attack;

    cout << "Enter Pokémon name: ";
    cin >> name;

    cout << "Choose type (Fire, Water, Grass, Electric, Ground): ";
    cin >> type;

    cout << "Level: ";
    cin >> level;
    cout << "HP: ";
    cin >> hp;
    cout << "Attack Power: ";
    cin >> attack;

    // Create an object of the appropriate subclass based on type input
    if (type == "Fire") return new FireType(name, level, hp, attack);
    if (type == "Water") return new WaterType(name, level, hp, attack);
    if (type == "Grass") return new GrassType(name, level, hp, attack);
    if (type == "Electric") return new ElectricType(name, level, hp, attack);
    if (type == "Ground") return new GroundType(name, level, hp, attack);

    // If invalid type, fall back to FireType
    cout << "Invalid type. Returning FireType by default.\n";
    return new FireType(name, level, hp, attack);
}

// Function to choose from a list of predefined Pokémon (like a Pokédex)
Pokemon* chooseFromDatabase() {
    auto templates = getPokemonTemplates(); // Gets predefined Pokémon list from database

    // Display list of available Pokémon
    cout << "\nChoose a predefined Pokémon:\n";
    for (int i = 0; i < templates.size(); ++i) {
        cout << i + 1 << ". " << templates[i].name
             << " (Type: " << templates[i].type
             << ", Level: " << templates[i].level
             << ", HP: " << templates[i].hp
             << ", ATK: " << templates[i].attackPower << ")\n";
    }

    int choice;
    cout << "Choice: ";
    cin >> choice;

    // Validate input, otherwise fallback to first Pokémon
    if (choice < 1 || choice > templates.size()) {
        cout << "Invalid choice. Returning default Pokémon.\n";
        return createFromTemplate(templates[0]);
    }

    return createFromTemplate(templates[choice - 1]);
}

// Displays the main menu to the player
void showMenu() {
    cout << "\n=== Pokémon Battle Simulator ===\n";
    cout << "1. Add Pokémon to Team\n";
    cout << "2. View Team\n";
    cout << "3. Save Team\n";
    cout << "4. Load Team\n";
    cout << "5. Start Battle\n";
    cout << "0. Exit\n";
    cout << "Select an option: ";
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    
    // Get the trainer's name from user input
    string trainerName;
    cout << "Enter your Trainer's name: ";
    cin >> trainerName;
    
    Trainer player(trainerName); // Create player Trainer object
    
    int choice;
    do {
        showMenu(); // Show menu options
        cin >> choice;
        
        switch (choice) {
            case 1: { // Add Pokémon
                cout << "\nChoose how to add a Pokémon:\n";
                cout << "1. Choose from pre-defined Pokémon\n";
                cout << "2. Create your own custom Pokémon\n";
                cout << "Choice: ";
                int subChoice;
                cin >> subChoice;
                
                Pokemon* p = nullptr;
                
                if (subChoice == 1) {
                    p = chooseFromDatabase(); // Choose from database
                } else if (subChoice == 2) {
                    p = createPokemon(); // Custom Pokémon creation
                } else {
                    cout << "Invalid option. Returning to main menu.\n";
                    break;
                }
                
                if(player.addPokemon(p)) { // Add selected Pokémon to the player's team
                    cout << p->getName() << " added to " << player.getName() << "'s team.\n";
                    break;
                }
                else {
                    delete p;
                }
            }
            case 2:
                player.viewTeam(); // View current team of Pokémon
                break;
                
            case 3: {
                // Save team to file
                string filename;
                cout << "Enter filename to save team: ";
                cin >> filename;
                player.saveTeam(filename);
                cout << "Team saved.\n";
                break;
            }
                
            case 4: {
                // Load team from file
                string filename;
                cout << "Enter filename to load team: ";
                cin >> filename;
                player.loadTeam(filename);
                break;
            }
                
            case 5: {
                // Start a battle with an AI opponent
                Trainer opponent("AI_Rival"); // Opponent trainer
                Battle b(&player, &opponent); // Create a battle between player and AI
                b.generateOpponentTeam(&opponent); // Randomly generate AI's team
                b.startBattle(); // Start the turn-based battle
                break;
            }
                
            case 0:
                cout << "Exiting game.\n";
                break;
                
            default:
                cout << "Invalid option.\n"; // Input validation
            }
                
        } while (choice != 0); // Repeat until user chooses to exit
        
        return 0;
    }

