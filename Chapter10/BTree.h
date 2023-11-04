#pragma once
#include<iostream>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);

//precondition:
//postcondition:
class BTree{
private:
	//the type of nodes are going to be integers containers
	int data;
	//will keep track of the left child
	BTree* left;
	//will keep track of the right child 
	BTree* right;
	//will keep track of the nodes
	BTree* root;
public:
	//defualt constructor
	BTree();
	//constructor to be able to input the values (nodes)
	BTree(int newData);

	//check if there are root or nodes
	bool empty() const;

	//member functions to insert, count, search, preorder, inorder, and postorder traversal, and delete 
	void insert(BTree* &node, int value);
	void count(BTree* node,int &count);
	bool search(BTree* node, int value);
	void preorderTraversal(const BTree* node);
	void inorderTraversal(const BTree* node);
	void postorderTraversal(const BTree* node);
	void deleteEntireTree(BTree* node);

	//member function main menu
	void mainInformation();
};

