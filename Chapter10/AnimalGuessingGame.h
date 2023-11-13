
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
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
class AnimalGuessingGame {
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

	AnimalGuessingGame(const string& data);

	void theTree();
	void saveToFile(AnimalGuessingGame* node, ostream& file);

	void playGame(AnimalGuessingGame* node);

	//member function for menu
	void mainInformation();
};
