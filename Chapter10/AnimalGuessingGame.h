#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool inquire(string prompt);
char inputChar(string prompt, char yes, char no);
string inputString(string prompt, bool spaces);
char inputChar(string prompt, string options);

template <class Item>
class AnimalGuessingGame{
private:
    Item data_field;
    AnimalGuessingGame* left_field;
    AnimalGuessingGame* right_field;
    static string remove_brackets(const string& str);
    static AnimalGuessingGame<Item>* build_tree_from_file(ifstream& file);

public:
    // TYPEDEF
    typedef Item value_type;

    // CONSTRUCTOR
    AnimalGuessingGame(const Item& init_data = Item(), AnimalGuessingGame* init_left = nullptr, AnimalGuessingGame* init_right = nullptr);

    // MODIFICATION MEMBER FUNCTIONS
    Item& data();
    AnimalGuessingGame*& left();
    AnimalGuessingGame*& right();
    void set_data(const Item& new_data);
    void set_left(AnimalGuessingGame* new_left);
    void set_right(AnimalGuessingGame* new_right);

    // CONSTANT MEMBER FUNCTIONS
    const Item& data() const;
    const AnimalGuessingGame* left() const;
    const AnimalGuessingGame* right() const;
    bool is_leaf() const;

    // MEMBER FUNCTIONS
    void tree_clear(AnimalGuessingGame<Item>*& root_ptr);
    AnimalGuessingGame<Item>* tree_copy(const AnimalGuessingGame<Item>* root_ptr);
    static AnimalGuessingGame<Item>* beginning_tree(const string& file_name);
    void ask_and_move(AnimalGuessingGame<string>*& current_ptr);
    void learn(AnimalGuessingGame<string>* leaf_ptr);
    void play(AnimalGuessingGame<string>* current_ptr);
    void save_tree_to_file(const string& file_name);
    static void save_tree_to_file_recursive(ofstream& file, AnimalGuessingGame<string>* root);
    void mainInformation();
};

