#include "AnimalGuessingGame.h"

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates 
AnimalGuessingGame::AnimalGuessingGame(): question(""),left(NULL), right(NULL), root(NULL) {}

AnimalGuessingGame::AnimalGuessingGame(string& q, AnimalGuessingGame* y, AnimalGuessingGame* n): question(q), left(y), right(n){}

void AnimalGuessingGame::theTree(){
    root = new AnimalGuessingGame("Is it a mammal?", new AnimalGuessingGame("Does it have stripes?", new AnimalGuessingGame("Zebra"), new AnimalGuessingGame("Lion")), new AnimalGuessingGame("Is it a bird?", new AnimalGuessingGame("Does it fly?", new AnimalGuessingGame("Eagle"), new AnimalGuessingGame("Penguin")), new AnimalGuessingGame("Gila monster")));

}


//precondition:
//postcondition:
void AnimalGuessingGame::saveToFile(AnimalGuessingGame* node, ostream& file){
    //if root (nodes) are null then return (base stop)
    if (node == NULL) {
        return;
    }
    //add the left first
    saveToFile(node->left, file);
    //then add the right one
    saveToFile(node->right, file);
}


//precondition:
//postcondition:
void AnimalGuessingGame::mainInformation(){
    system("cls");
    char choice;
    //create text file that opens and write to file
    ofstream textFile;
    textFile.open("animal.txt");
    do {
        cout << "\n\t3> Animal Guessing Game";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\n\tA game tree for a simple game of 'animal' twenty questions would look like: \n";
        cout << "\n\n\n\n\tA learning version of twenty questions: one that not only plays the game, but learns new\n\tobjects when it loses.\n";
        cout << "\n\n\tWelcome to Animal Guessing Game";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\tA> Play the game";
        cout << "\n\t\tB> Save the game file";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(82, char(205)) << "\n";
        choice = inputChar("\t\tOption: ", static_cast<std::string>("AB0"));

        switch (toupper(choice)) {
        case 'A': {
        }
                break;
        case 'B': {
            saveToFile(root, textFile);
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}
