#include "AnimalGuessingGame.h"

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates 
AnimalGuessingGame::AnimalGuessingGame() : question(""), left(NULL), right(NULL), root(NULL) {}

AnimalGuessingGame::AnimalGuessingGame(const string& newQuestion) :question(newQuestion), left(NULL), right(NULL), root(NULL) {}

void AnimalGuessingGame::theTree() {
    //the root
    root = new AnimalGuessingGame("\n\tIs it a mammal?");
    //left subtree
    root->left = new AnimalGuessingGame("\n\tDoes it have stripes?");
    root->left->left = new AnimalGuessingGame("\n\tZebra");
    root->left->right = new AnimalGuessingGame("\n\tLion");
    //right subtree
    root->right = new AnimalGuessingGame("\n\tIs it a bird?");
    root->right->left = new AnimalGuessingGame("\n\tDoes it fly?");
    root->right->left->left = new AnimalGuessingGame("\n\tEagle");
    root->right->left->right = new AnimalGuessingGame("\n\tPenguin");
    root->right->right = new AnimalGuessingGame("\n\tGila monster");
}

void AnimalGuessingGame::playGame(AnimalGuessingGame* node) {
    while (node->left && node->right) {
        //call the nodes, and ask the questions
        cout << node->question << " (Y-yes/no): ";
        char choice = inputChar("", static_cast<string>("YN)"));

        //if yes then go to the left subtree
        if (toupper(choice) == 'Y') {
            node = node->left;
        }
        //if  no then go to the right subtree
        else if (toupper(choice) == 'N') {
            node = node->right;
        }
    }

    //if the answer is at the leaf node, print the animal
    cout << "\n\tThe animal is: " << node->question << endl;
}

//precondition:
//postcondition:
void AnimalGuessingGame::saveToFile(AnimalGuessingGame* node, ostream& file) {
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
void AnimalGuessingGame::mainInformation() {
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
            system("cls");
            cout << "\n\tThink of animal and press the RETURN/ENTER key to begin...";
            system("pause");
            playGame(root);
            system("pause");
            system("cls");
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
