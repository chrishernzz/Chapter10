#include "AnimalGuessingGame.h"

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates 
AnimalGuessingGame::AnimalGuessingGame() : question(""), left(NULL), right(NULL), root(NULL) {}

//precondition: going to call the constructor class
//postcondition: going to then initialize the privates and data will now have newData
AnimalGuessingGame::AnimalGuessingGame(const string& newQuestion) :question(newQuestion), left(NULL), right(NULL), root(NULL) {}
//precondition: going to call the animal guessing game
//postcondition: going to then call the recursive function deleteEntireTree() and pass in the root and then set it to NULL
AnimalGuessingGame::~AnimalGuessingGame() {
    //deallocate the memory
    delete(root);
    //make sure the root is set to null to show that there are no more nodes or else it will have garbage data
    root = NULL;
}
//precondition: going to pass in the animal guessing class class
//postcondition: going to then delete the node (deallocate the nodes so memory does not leak)
void AnimalGuessingGame::deleteEntireTree(AnimalGuessingGame* node) {
    if (node == NULL) {
        return;
    }
    //first delete the left subtree 
    deleteEntireTree(node->left);
    //then delete the right subtree
    deleteEntireTree(node->right);

    //delete the current node
    delete node;
}

//precondition: going to call the tree that will hold the information
//postcondition: going to then call the root that hold the nodes, going to set the root, left subtree, and then right subtree, checking if the file is open and if not then first write
void AnimalGuessingGame::theTree() {
    ifstream readFile("animal.txt");
    //check if file is open (if there is data in the animal.txt
    if (readFile.is_open()) {
        root = loadFromFile(readFile);
        readFile.close();
    }
    //if there is no file then create and input the information
    else {
        root = new AnimalGuessingGame("Is it a mammal?");
        root->left = new AnimalGuessingGame("Does it have stripes?");
        root->left->left = new AnimalGuessingGame("Zebra");
        root->left->right = new AnimalGuessingGame("Lion");
        root->right = new AnimalGuessingGame("Is it a bird?");
        root->right->left = new AnimalGuessingGame("Does it fly?");
        root->right->left->left = new AnimalGuessingGame("Eagle");
        root->right->left->right = new AnimalGuessingGame("Penguin");
        root->right->right = new AnimalGuessingGame("Gila monster");
        //you then have to write it to the file
        ofstream writeFile("animal.txt");
        if (writeFile.is_open()) {
            saveToFile(root, writeFile);
            writeFile.close();
        }
        else {
            cout << "Error: File is not open for writing." << endl;
        }
    }
}
//precondition: going to pass in a read file for reading
//postcondition: going to then read the file and get the information 
AnimalGuessingGame* AnimalGuessingGame::loadFromFile(ifstream& readFile) {
    string line;
    if (!getline(readFile, line) || line.empty()) {
        return NULL;
    }

    //get rid of brackets
    line = line.substr(1, line.size() - 2);
    AnimalGuessingGame* node = new AnimalGuessingGame(line);

    //check if this is a leaf node or a question node by peeking at the next character
    if (readFile.peek() == '[') {
        node->left = loadFromFile(readFile);
        node->right = loadFromFile(readFile);
    }
    return node;
}
//precondition: going to pass in two arguments that one accepts a node, the other one to open the file
//postcondition: going to then write to the file
void AnimalGuessingGame::saveToFile(AnimalGuessingGame* node, ostream& file) {
    //base case
    if (node == NULL) {
        return;
    }
    if (file.fail()) {
        return;
    }
    //save the current node's question to the file
    file << "[" << node->question << "]" << endl;
    //add the left first
    saveToFile(node->left, file);
    //then add the right one
    saveToFile(node->right, file);
}


//precondition: going to pass in the class that is a node as an argument
//postcondition: going to then loop the questions and check if they are true or not, going to determine if the animal was right
void AnimalGuessingGame::playGame(AnimalGuessingGame* node) {
    //base case
    if (node == NULL) {
        cout << "\n\t\tERROR: NO DATA TO PLAY GAME...";
        return;
    }
    //check the left and right questions
    while (node->left && node->right) {
        cout << "\n\t" << node->question << " (Y-yes/N-no): ";
        char choice = inputChar("", static_cast<string>("YN"));
        //if user clicks Yes then go to the left subtree
        if (toupper(choice) == 'Y') {
            node = node->left;
        }
        //go to right subtree
        else {
            node = node->right;
        }
    }

    cout << "\n\tMy guess is " << node->question << ". Am I right (y/n): ";
    char choice2 = inputChar("", static_cast<string>("YN"));
    //if answer is Yes then it is right along
    if (toupper(choice2) == 'Y') {
        cout << "\n\tYes, I knew it all along!\n\n";
    }
    else {
        string newAnimal = inputString("\n\tI give up. What are you? ", false);
        string newQuestion = inputString("\n\tPlease specify a yes/no question that distinguishes a " + newAnimal + " from a " + node->question + ": ", true);
        cout << "\n\tAs a " << newAnimal << ", does it " << newQuestion << " (y/n): ";
        char choice3 = inputChar("", static_cast<string>("YN"));

        node->right = new AnimalGuessingGame(newAnimal);
        node->left = new AnimalGuessingGame(node->question);
        node->question = newQuestion;
        if (toupper(choice3) == 'Y') {
            swap(node->left, node->right);
        }

        //write the information to the text file
        ofstream writeFile("animal.txt");
        if (writeFile.is_open()) {
            saveToFile(root, writeFile);
            writeFile.close();
        }
        else {
            cout << "\n\tError: Unable to open file for writing.\n\n";
        }
    }
}
//precondition: going to print the information
//postcondition: going to create a menu that has options 
void AnimalGuessingGame::mainInformation() {
    system("cls");
    char choice;
    string fileName = "animal.txt";
    //create text file that opens and write to file
    ofstream textFile;
    textFile.open(fileName);
    do {
        cout << "\n\t3> Animal Guessing Game";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\n\tA game tree for a simple game of 'animal' twenty questions would look like: \n";
        cout << "\n\t\t[ Is it a mammal? ]" << endl;
        cout << "                    /         \\" << endl;
        cout << "                   /           \\" << endl;
        cout << "[ Does it have stripes? ]     [ Is it a bird? ]" << endl;
        cout << "         /       \\                  /       \\" << endl;
        cout << "        /         \\                /         \\" << endl;
        cout << "( Zebra )    ( Lion )    [ Does it fly? ]  ( Gila monster )" << endl;
        cout << "                           /       \\" << endl;
        cout << "                          /         \\" << endl;
        cout << "                    ( Eagle )     ( Penguin )" << endl;
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
            cout << "\n\tNew data file. " << fileName << ", has been saved.\n\n";
            system("pause");
            system("cls");
            //closing file
            textFile.close();
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}