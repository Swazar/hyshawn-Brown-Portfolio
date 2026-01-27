//Group C Members: Thyshawn Brown(20234405), Kya Green (20234676), Tareek Lowe (20234662), Tarique Reid (20207904), Rajae Taylor(2011970)

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Player class
class Player {
public:
    string name;
    int lives;
    int stops;
    bool hasFoundTreasure;
    string title;
    bool itemsCollected[5]; // Track items collected from each city

    Player() {
        lives = 3;
        stops = 0;
        hasFoundTreasure = false;
        title = "Adventurer";
        for (int i = 0; i < 5; i++) {
            itemsCollected[i] = false;
        }
    }

    void takeDamage() {
        lives--;
        cout << "Alas! The bandits have ambushed you! Lives left: " << lives << endl;
    }

    void findTreasure() {
        hasFoundTreasure = true;
        cout << "Victory! " << name << ", you have uncovered the Lost Treasure of King Arthur" << endl;
    }

    void setName() {
        cout << "Enter your name, brave adventurer: ";
        cin >> name;
    }

    bool hasAllItems() {
        int itemCount = 0;
        for (int i = 0; i < 5; i++) {
            if (itemsCollected[i]) {
                itemCount++;
            }
        }
        return itemCount >= 4;
    }
};

// Building class
class Building {
public:
    string name;
    Building(string name) : name(name) {}
    virtual void displayBuildingInfo() {
        cout << "You are at the " << name << "." << endl;
    }

    virtual bool askQuestion() {
        return false;
    }
};

// City Hall subclass
class CityHall : public Building {
public:
    CityHall() : Building("The Great Hall") {}
    void displayBuildingInfo() override {
        cout << "You are at the Great Hall, where the city's governance takes place." << endl;
    }

    bool askQuestion() override {
        string questions[3] = {
            "What is the name of King Arthur's legendary sword?\n1. Excalibur\n2. Durandal\n3. Gram\n4. Joyeuse",
            "Who was the first king of England?\n1. Alfred the Great\n2. William the Conqueror\n3. Henry VIII\n4. Richard the Lionheart",
            "What is the name of the legendary castle of King Arthur?\n1. Camelot\n2. Tintagel\n3. Windsor\n4. Dover"
        };
        string correctAnswers[3] = {"1", "1", "1"};
        int questionIndex = rand() % 3;
        string answer;
        int attempts = 3;

        while (attempts > 0) {
            cout << questions[questionIndex] << " (Attempts left: " << attempts << "): ";
            cin >> answer;
            if (answer == correctAnswers[questionIndex]) {
                cout << "Correct! You have claimed the item from the Great Hall." << endl;
                return true;
            } else {
                cout << "Incorrect! Try again." << endl;
                attempts--;
            }
        }
        cout << "You have failed to answer the question correctly." << endl;
        return false;
    }
};

// Church subclass
class Church : public Building {
public:
    Church() : Building("The Sacred Chapel") {}
    void displayBuildingInfo() override {
        cout << "You are at the Sacred Chapel, a place of worship and peace." << endl;
    }

    bool askQuestion() override {
        string questions[3] = {
            "What is the name of the legendary cup used by Jesus at the Last Supper?\n1. Holy Grail\n2. Chalice of Antioch\n3. Cup of Nestor\n4. Goblet of Fire",
            "Who was the first Christian emperor of Rome?\n1. Constantine\n2. Augustus\n3. Nero\n4. Julius Caesar",
            "What is the name of the famous cathedral in Paris?\n1. Notre-Dame\n2. Westminster Abbey\n3. St. Paul's Cathedral\n4. Sagrada Familia"
        };
        string correctAnswers[3] = {"1", "1", "1"};
        int questionIndex = rand() % 3;
        string answer;
        int attempts = 3;

        while (attempts > 0) {
            cout << questions[questionIndex] << " (Attempts left: " << attempts << "): ";
            cin >> answer;
            if (answer == correctAnswers[questionIndex]) {
                cout << "Correct! You have claimed the item from the Sacred Chapel." << endl;
                return true;
            } else {
                cout << "Incorrect! Try again." << endl;
                attempts--;
            }
        }
        cout << "You have failed to answer the question correctly." << endl;
        return false;
    }
};

// Library subclass
class Library : public Building {
public:
    Library() : Building("The Ancient Library") {}
    void displayBuildingInfo() override {
        cout << "You are at the Ancient Library, a repository of ancient knowledge and wisdom." << endl;
    }

    bool askQuestion() override {
        string questions[3] = {
            "What is the name of the wizard who advised King Arthur?\n1. Merlin\n2. Gandalf\n3. Dumbledore\n4. Saruman",
            "Who wrote 'The Canterbury Tales'?\n1. Geoffrey Chaucer\n2. William Shakespeare\n3. John Milton\n4. Thomas More",
            "What is the name of the ancient library in Egypt?\n1. Library of Alexandria\n2. Library of Pergamum\n3. Library of Ephesus\n4. Library of Nineveh"
        };
        string correctAnswers[3] = {"1", "1", "1"};
        int questionIndex = rand() % 3;
        string answer;
        int attempts = 3;

        while (attempts > 0) {
            cout << questions[questionIndex] << " (Attempts left: " << attempts << "): ";
            cin >> answer;
            if (answer == correctAnswers[questionIndex]) {
                cout << "Correct! You have claimed the item from the Ancient Library." << endl;
                return true;
            } else {
                cout << "Incorrect! Try again." << endl;
                attempts--;
            }
        }
        cout << "You have failed to answer the question correctly." << endl;
        return false;
    }
};

// Shopping Center subclass
class ShoppingCenter : public Building {
public:
    ShoppingCenter() : Building("The Market Square") {}
    void displayBuildingInfo() override {
        cout << "You are at the Market Square, bustling with merchants and traders." << endl;
    }

    bool askQuestion() override {
        string questions[3] = {
            "What is the name of the legendary island where King Arthur was taken to recover from his wounds?\n1. Avalon\n2. Atlantis\n3. El Dorado\n4. Shangri-La",
            "What was the main currency used in medieval England?\n1. Pound Sterling\n2. Florin\n3. Ducat\n4. Mark",
            "What is the name of the famous market in Istanbul?\n1. Grand Bazaar\n2. Souq Waqif\n3. Khan el-Khalili\n4. Mercado de San Miguel"
        };
        string correctAnswers[3] = {"1", "1", "1"};
        int questionIndex = rand() % 3;
        string answer;
        int attempts = 3;

        while (attempts > 0) {
            cout << questions[questionIndex] << " (Attempts left: " << attempts << "): ";
            cin >> answer;
            if (answer == correctAnswers[questionIndex]) {
                cout << "Correct! You have claimed the item from the Market Square." << endl;
                return true;
            } else {
                cout << "Incorrect! Try again." << endl;
                attempts--;
            }
        }
        cout << "You have failed to answer the question correctly." << endl;
        return false;
    }
};

// The City base class
class City {
public:
    string name;
    Building* buildings[4];

    City() {
        buildings[0] = new CityHall();
        buildings[1] = new Church();
        buildings[2] = new Library();
        buildings[3] = new ShoppingCenter();
    }

    virtual void displayCityInfo() {
        cout << "You are in the fabled city of " << name << "." << endl;
    }

    void displayBuildings() {
        cout << "Buildings in " << name << ":" << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << buildings[i]->name << endl;
        }
    }

    bool visitBuilding(int buildingIndex) {
        if (buildingIndex >= 0 && buildingIndex < 4) {
            buildings[buildingIndex]->displayBuildingInfo();
            if (buildings[buildingIndex]->askQuestion()) {
                cout << "You have claimed an item from the " << buildings[buildingIndex]->name << "." << endl;
                return true;
            }
        } else {
            cout << "Invalid building choice." << endl;
        }
        return false;
    }
};

// City classes
class London : public City {
public:
    London() {
        name = "London, the Heart of the Realm";
    }

    void displayCityInfo() override {
        cout << "You are in London, the bustling heart of the kingdom, where knights and traders alike gather." << endl;
    }
};

class Paris : public City {
public:
    Paris() {
        name = "Paris, the City of Eternal Love";
    }

    void displayCityInfo() override {
        cout << "You have arrived in Paris, a land of romance, grand feasts, and ancient lore." << endl;
    }
};

class Istanbul : public City {
public:
    Istanbul() {
        name = "Istanbul, the Crossroads of Empires";
    }

    void displayCityInfo() override {
        cout << "Welcome to Istanbul, a city where East meets West, and ancient warriors roamed the streets." << endl;
    }
};

class Islamabad : public City {
public:
    Islamabad() {
        name = "Islamabad, the Oasis of Tranquility";
    }

    void displayCityInfo() override {
        cout << "You stand in Islamabad, a serene city surrounded by mountains, a place of refuge for travelers." << endl;
    }
};

class Beijing : public City {
public:
    Beijing() {
        name = "Beijing, the City of the Rising Sun";
    }

    void displayCityInfo() override {
        cout << "You are in Beijing, a place where dragons once roamed and mighty emperors ruled the land." << endl;
    }
};

// The Road class
class Road {
public:
    string roadName;
    City* destinationCity;
    string danger;

    Road(string name, City* city, string dangerLevel) : roadName(name), destinationCity(city), danger(dangerLevel) {}

    void travel() {
        cout << "You venture along the " << roadName << "..." << endl;
        if (!danger.empty()) {
            cout << "Beware, adventurer! The path ahead is fraught with " << danger << "!" << endl;
        }
        destinationCity->displayCityInfo();
    }
};

// Cyclops encounter
bool encounterCyclops() {
    if (rand() % 100 < 35) {
        cout << "A giant cyclops blocks your path and demands you answer a riddle to pass." << endl;
        string riddles[3] = {
            "What has roots as nobody sees, is taller than trees, up, up it goes, and yet never grows?\n1. Mountain\n2. River\n3. Tree\n4. Cloud",
            "Voiceless it cries, wingless flutters, toothless bites, mouthless mutters.\n1. Wind\n2. Fire\n3. Water\n4. Earth",
            "This thing all things devours: birds, beasts, trees, flowers; gnaws iron, bites steel; grinds hard stones to meal; slays king, ruins town, and beats high mountain down.\n1. Time\n2. Fire\n3. Water\n4. Earth"
        };
        string correctAnswers[3] = {"1", "1", "1"};
        int riddleIndex = rand() % 3;
        string answer;
        int attempts = 3;

        while (attempts > 0) {
            cout << riddles[riddleIndex] << " (Attempts left: " << attempts << "): ";
            cin >> answer;
            if (answer == correctAnswers[riddleIndex]) {
                cout << "Correct! The cyclops lets you pass." << endl;
                return true;
            } else {
                cout << "Incorrect! Try again." << endl;
                attempts--;
            }
        }
        cout << "You have failed to answer the riddle correctly. The cyclops attacks you!" << endl;
        return false;
    }
    return true;
}

// Main Menu
void displayMainMenu() {
    cout << "\n===================================" << endl;
    cout << "   The Lost Treasure of King Arthur" << endl;
    cout << "        (A Medieval Adventure)     " << endl;
    cout << "===================================" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Rules" << endl;
    cout << "3. Exit" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Choose your fate, hero (1-3): ";
}

//the rules of the game
void displayRules() {
    cout << "\n===================================" << endl;
    cout << "         The Sacred Rules of the Quest         " << endl;
    cout << "===================================" << endl;
    cout << "1. Thou must find the fabled Lost Treasure of King Arthur, hidden deep within the lands." << endl;
    cout << "2. The kingdom is divided into five cities: London, Paris, Istanbul, Islamabad, and Beijing." << endl;
    cout << "3. Each city contains two mystical paths, leading thee to new lands and dangers." << endl;
    cout << "4. Only one of these cities contains the treasure, but it is not the first city." << endl;
    cout << "5. Thou must collect 4 items from the buildings in the cities." << endl;
    cout << "6. Once thou hast collected 4 items, thou must travel from city to city to find the treasure." << endl;
    cout << "7. The treasure has a 50% chance of being in each city thou visitest." << endl;
    cout << "8. Thou hast 7 stops before the bandits, who seek the treasure, catch thee." << endl;
    cout << "9. If thy lives reach zero, or if thou dost find the treasure, the quest shall end." << endl;
    cout << "10. Beware of the cyclops on the road, answer his riddle correctly to pass or lose a life." << endl;
    cout << "===================================" << endl;
}

// function to play game
void playGame() {
    srand(time(0)); //random number generation

    Player player;
    player.setName(); // Set the player's name

    // The different cities
    City* cities[5];
    cities[0] = new London();
    cities[1] = new Paris();
    cities[2] = new Istanbul();
    cities[3] = new Islamabad();
    cities[4] = new Beijing();

    //make code to assign the treasure to a city but not the first city
    int treasureCityIndex = rand() % 4 + 1; 
    cout << "The treasure is hidden somewhere in the kingdom, hero..." << endl;

    // Create roads between cities
    Road roads[4] = {
        Road("The Whispering Path", cities[1], "treacherous bandits and beasts"),
        Road("The Silver Mountain Trail", cities[2], "a storm of mystical creatures"),
        Road("The King's Road", cities[3], "an ambush of thieves"),
        Road("The Dragon's Path", cities[4], "the howling winds of the north")
    };

    // Game loop
    while (player.lives > 0 && !player.hasFoundTreasure && player.stops < 7) {
        cout << "\n-------------------------------" << endl;
        cout << "Lives: " << player.lives << " | Stops: " << player.stops << endl;

        if (!player.hasAllItems()) {
            cout << "Choose a path to travel (1-4): " << endl;
            cout << "1. The Whispering Path - " << cities[1]->name << endl;
            cout << "2. The Silver Mountain Trail - " << cities[2]->name << endl;
            cout << "3. The King's Road - " << cities[3]->name << endl;
            cout << "4. The Dragon's Path - " << cities[4]->name << endl;
            cout << "Your choice, noble adventurer: ";

            int roadChoice;
            while (!(cin >> roadChoice) || roadChoice < 1 || roadChoice > 4) {
                cout << "Invalid choice. Please choose a path (1-4): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Travel on the road
            roads[roadChoice - 1].travel();
            player.stops++; // Increment the stop count after each travel

            if (player.stops >= 7) {
                cout << "Alas, the bandits have caught up with you after 7 stops! The journey ends here." << endl;
                break;
            }

            // Fork in the road
            cout << "You come to a fork in the road. Choose a path (1-2): " << endl;
            cout << "1. The Enchanted Trail" << endl;
            cout << "2. The Shadowy Passage" << endl;
            cout << "Your choice: ";
            int forkChoice;
            while (!(cin >> forkChoice) || forkChoice < 1 || forkChoice > 2) {
                cout << "Invalid choice. Please choose a path (1-2): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Cyclops encounter
            if (!encounterCyclops()) {
                player.takeDamage(); // Lose a life if the player fails the cyclops riddle
                continue;
            }

            // Visit a building in the city
            cout << "Choose a building to visit (1-4): " << endl;
            cities[player.stops % 5]->displayBuildings();
            int buildingChoice;
            while (!(cin >> buildingChoice) || buildingChoice < 1 || buildingChoice > 4) {
                cout << "Invalid choice. Please choose a building (1-4): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (!cities[player.stops % 5]->visitBuilding(buildingChoice - 1)) {
                player.takeDamage(); // Lose a life if the player fails all attempts
            } else {
                player.itemsCollected[player.stops % 5] = true;
                cout << "Collected item from city Item:" << player.stops % 5 << endl; // Debug statement
            }
        } else {
            // Travel from city to city to find the treasure
            cout << "Choose a city to travel to (1-5): " << endl;
            cout << "1. " << cities[0]->name << endl;
            cout << "2. " << cities[1]->name << endl;
            cout << "3. " << cities[2]->name << endl;
            cout << "4. " << cities[3]->name << endl;
            cout << "5. " << cities[4]->name << endl;
            cout << "Your choice, noble adventurer: ";

            int cityChoice;
            while (!(cin >> cityChoice) || cityChoice < 1 || cityChoice > 5) {
                cout << "Invalid choice. Please choose a city (1-5): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Travel to the chosen city
            cities[cityChoice - 1]->displayCityInfo();
            player.stops++; // Increment the stop count after each travel

            if (player.stops >= 7) {
                cout << "Alas, the bandits have caught up with you after 7 stops! The journey ends here." << endl;
                break;
            }

            // Check if the treasure is in the city
            if (rand() % 2 == 0) {
                player.findTreasure();
            } else {
                cout << "The treasure is not in this city. Keep searching, brave adventurer!" << endl;
            }
        }
    }

    if (player.hasFoundTreasure) {
        cout << "Congratulations! You have found the Lost Treasure!" << endl;
    } else if (player.lives <= 0) {
        cout << "The journey has ended, and your quest for the treasure has failed." << endl;
    }
}

// Main function
int main() {
    int choice;
    bool playing = true;

    while (playing) {
        displayMainMenu();
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Invalid choice. Please choose your fate (1-3): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayRules();
                break;
            case 3:
                cout << "Thank you for playing, noble adventurer! Farewell!" << endl;
                playing = false;
                break;
            default:
                cout << "Invalid choice, hero. Choose again." << endl;
        }

        if (playing) {
            char playAgain;
            cout << "Do you wish to embark on another quest, adventurer? (y/n): ";
            while (!(cin >> playAgain) || (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')) {
                cout << "Invalid choice. Do you wish to embark on another quest, adventurer? (y/n): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (playAgain == 'n' || playAgain == 'N') {
                playing = false;
                cout << "May the winds of fortune guide you, adventurer!" << endl;
            }
        }
    }

    return 0;
}
