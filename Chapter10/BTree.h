#pragma once
#include<iostream>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);

class BTree{
private:
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
	//constructor
	BTree(int newData);

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

