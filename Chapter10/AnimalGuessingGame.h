#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);

//precondition:
//postcondition:
class AnimalGuessingGame{
private:
	string question;
	//this well be for yes
	AnimalGuessingGame* left;
	//this will be for no
	AnimalGuessingGame* right;
	//will hold the nodes 
	AnimalGuessingGame* root;
public:
	//default constructor
	AnimalGuessingGame();

	AnimalGuessingGame(string& q, AnimalGuessingGame* y, AnimalGuessingGame* n);
	
	void theTree();
	void saveToFile(AnimalGuessingGame* node, ostream& file);


	//member function for menu
	void mainInformation();
};

