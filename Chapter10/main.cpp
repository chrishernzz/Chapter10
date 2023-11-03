//Name: Christian Hernandez
//Date: 11/15/2023
//subscription: CMPR131

//Credit: Christian Hernandez,Bryan Alarcon,Thanh Tran, Joe Bryant,Erik Santana, Saul Merino, Otoniel Torres Bernal, and John Kim

#include<iostream>
#include"input (1).h"
#include"BTree.h"
using namespace std;

//prototype
int menuOption();
void challenge1();
void challenge2();
void challenge3();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		case 3: challenge3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}
//precondition: making a menu option
//postcondition: it will return an int (the choice of the menu)
int menuOption() {
	system("cls");
	cout << "\n\tCMPR131 Chapter 10: Trees by Christian Hernandez(11/6/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Trees of strings";
	cout << "\n\t\t2> Trees container of integers";
	cout << "\n\t\t3> Animal Guessing Game";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting c1 from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 3);
}

//precondition: 
//postcondition: 
void challenge1() {

}
//precondition: going to call my BTree class
//postcondition: going to then call my main menu information that has the options to do
void challenge2() {
	BTree menu;
	menu.mainInformation();
}
//precondition: going to call my Costco class
//postcondition: going to then call my mainMenuInformation function that will have all the information and the menus as well 
void challenge3() {

}
