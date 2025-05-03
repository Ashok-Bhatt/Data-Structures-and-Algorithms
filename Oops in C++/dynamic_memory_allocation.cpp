#include <iostream>
using namespace std;

class Pokemon{
    public:
    int pokedex;
    string type;
};

int main() {

    Pokemon Pikachu;
    Pikachu.pokedex = 25;
    Pikachu.type = "Electric";

    Pokemon Charizard;
    Charizard.pokedex = 6;
    Charizard.type = "Fire";

    Pokemon* Meowth = new Pokemon;
    (*Meowth).pokedex = 52;
    Meowth->type = "Normal";

    cout << "Pikachu:" << endl << "Pokedex Entry: " << Pikachu.pokedex << endl << "Pokemon Type: " << Pikachu.type << "\n\n";
    cout << "Charizard:" << endl << "Pokedex Entry: " << Charizard.pokedex << endl << "Pokemon Type: " << Charizard.type << "\n\n";
    cout << "Meowth:" << endl << "Pokedex Entry: " << Meowth->pokedex << endl << "Pokemon Type: " << Meowth->type << "\n\n";

    delete Meowth;
    
}