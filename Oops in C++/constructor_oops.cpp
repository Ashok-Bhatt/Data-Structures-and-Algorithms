#include <iostream>
using namespace std;

class Pokemon{

    public:
    string name;
    int pokedex;
    string type;

    Pokemon(){
    cout <<"New Pokemon Created." << endl;
    };

    Pokemon(string name, int pokedex, string type){
    
    this->name = name;
    this->pokedex = pokedex;
    this->type = type;
    cout  << this->name <<" Pokemon Created:" << endl;
    cout << "Name: " << this->name << "\t\t" << "Pokedex No.: " << this->pokedex << "\t\t" << "Type: " << this->type << endl;
    };

    Pokemon(const Pokemon& temp) {
    this->name = temp.name;
    this->pokedex = temp.pokedex;
    this->type = temp.type;
    }

    void setName(string n){
        name = n;
    }

};

int main() {

    Pokemon Pikachu;
    Pikachu.name = "Pikachu";
    Pikachu.pokedex = 25;
    Pikachu.type = "Electric";

    Pokemon Charizard("Charizard", 6, "Fire");

    // Shallow Copy
    Pokemon Charmander(Pikachu);
    cout << Pikachu.name << "       " << Charmander.name << endl;
    Charmander.setName("Charmander");
    cout << Pikachu.name << "       " << Charmander.name << endl;

    // Deep Copy
    Pokemon Squirtle(Pikachu);

    cout << Pikachu.name << "       " << Squirtle.name << endl;
    Squirtle.setName("Squirtle");
    cout << Pikachu.name << "       " << Squirtle.name << endl;
}