#include "BTree.h"

//precondition: going to call the default constructor class
//postcondition: going to then intialize the privates 
BTree::BTree(): data(0), left(NULL), right(NULL),root(NULL) {}
//precondition: going to call the constructor class
//postcondition: going to then intialize the privates and data will now have newData
BTree::BTree(int newData):data(newData), left(NULL),right(NULL),root(NULL){}

//precondition: going to make a function to check if its empty
//postcondition: going to then return that root is null meaning there are no nodes, if it is then its empty
bool BTree::empty() const{
    //if the root is null, then there are no nodes or root
    if (root == NULL) {
        return true;
    }
    else {
        return false;
    }
}

//precondition: going to pass in the BTree class and the input value
//postcondition: going to then check if the value is less than the current data, if it is go left and if not go right and recursive 
void BTree::insert(BTree* &node, int value){
    //first check if the root or subtree is null, if its is run this and set the new node to it
    if (node == NULL) {
        node =  new BTree(value);
    }
    //if the value is less than the data(node) then it will go to the left side of the subtree
    else if (value < node->data) {
        insert(node->left, value);
    }
    //else if its greater than then go to the right of the subtree
    else {
        insert(node->right, value);
    }
}

//precondition: going to pass in the BTree class and counts
//postcondition: going to then preincrement the counts to keep track of both subtrees
void BTree::count(BTree* node,int &counts){
    //if root (nodes) are null then return
    if (node == NULL) {
        return;
    }

    //preincrement
    ++counts;
    //will count all the left child nodes
    count(node->left, counts);
    //will count all the right child nodes
    count(node->right, counts);
}
//precondition: going to pass in the BTree class and the input value
//postcondition: going to then check if the data (nodes) is equal to the value
bool BTree::search(BTree* node, int value){
    //if root (nodes) are null then return
    if (node == NULL) {
        return false;
    }
    //going to search for the node in the data, if its the same as value then return true;
    if (node->data == value) {
        return true;
    }
    //going to chekc if they are found in left and right subtrees
    bool found = search(node->left, value);
    bool found2= search(node->right, value);
    return found || found2;
}

//precondition: going to pass in the BTree class
//postcondition: going to then print the pre order traversal 
void BTree::preorderTraversal(const BTree* node) {
    //if root (nodes) are null then return
    if (node == NULL) {
        return;
    }

    cout << "\t\t" << node->data << endl;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
//precondition: going to pass in the BTree class
//postcondition: going to then print the in order traversal 
void BTree::inorderTraversal(const BTree* node){
    //if root (nodes) are null then return
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    cout << "\t\t" << node->data << endl;
    inorderTraversal(node->right);
}
//precondition: going to pass in the BTree class
//postcondition: going to then print the post order traversal 
void BTree::postorderTraversal(const BTree* node){
    //if root (nodes) are null then return
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << "\t\t" << node->data << endl;
}
//precondition: going to pass in the BTree class
//postcondition: going to then delete the node and set it to a null
void BTree::deleteEntireTree(BTree* node){
    //if root (nodes) are null then return
    if (node == NULL) {
        return;
    }
    //going to delete all the left subtrees
    deleteEntireTree(node->left);
    //going to then delete all the right subtrees
    deleteEntireTree(node->right);

    //this will delete each nodes (current ones)
    delete node;
    //set the node back to a null 
    node = NULL;
    //make sure the root is set to null to show that there are no more nodes or else it will have garbage data
    root = NULL;
}

//precondition: going to print the information
//postcondition: going to create a menu that has options 
void BTree::mainInformation(){
    system("cls");
    char choice;
    do {
        cout << "\n\t1> bTree container";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\tA> Insert a node/leaf";
        cout << "\n\t\tB> Count of Nodes/Leaves";
        cout << "\n\t\tC> Search a node/leaf";
        cout << "\n\t\tD> Pre-order traversal";
        cout << "\n\t\tE> In-order traversal";
        cout << "\n\t\tF> Post-order traversal";
        cout << "\n\t\tG> Delete the entire tree";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(82, char(205)) << "\n";
        choice = inputChar("\t\tOption: ", static_cast<std::string>("ABCDEFG0)"));

        switch (toupper(choice)) {
        case 'A': {
            int insertInput = inputInteger("\n\t\tEnter an integer: ");
            insert(root,insertInput);
            cout << "\n";
            system("pause");
            system("cls");
        }
                break;
        case 'B': {
            int counts = 0;
            //if the binary tree is empty, then error
            if (empty()) {
                cout << "\n\t\tERROR: bTree is empty.";
            }
            else {
                count(root, counts);
                cout << "\n\t\tCount of Nodes = " << counts;
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'C': {
            //if the binary tree is empty, then error
            if (empty()) {
                cout << "\n\t\tERROR: bTree is empty.";
            }
            else {
                int searchInput = inputInteger("\n\t\tEnter an integer key to search: ");
                bool found = search(root, searchInput);
                if (found) {
                    cout << "\n\t\t" << searchInput << " is found.";
                }
                else {
                    cout << "\n\t\t" << searchInput << " cannot be found.";
                }
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'D': {
            //if the binary tree is empty, then error
            if (empty()) {
                cout << "\n\t\tERROR: bTree is empty.\n";
            }
            else {
                cout << "\n\t\tPre-order traversal of bTree with nodes:\n";
                preorderTraversal(root);
            }
            cout << "\n";
            system("pause");
            system("cls");
        }
                break;
        case 'E': {
            //if the binary tree is empty, then error
            if (empty()) {
                cout << "\n\t\tERROR: bTree is empty.\n";
            }
            else {
                cout << "\n\t\tIn-order traversal of bTree with nodes:\n";
                inorderTraversal(root);
            }
            cout << "\n";
            system("pause");
            system("cls");
        }
                break;
        case 'F': {
            //if the binary tree is empty, then error
            if (empty()) {
                cout << "\n\t\tERROR: bTree is empty.\n";
            }
            else {
                cout << "\n\t\tPost-order traversal of bTree with nodes:\n";
                postorderTraversal(root);
            }
            cout << "\n";
            system("pause");
            system("cls");
        }
                break;
        case 'G': {
            int counts = 0;
            //if the binary tree is empty, then error
            if (empty()) {
                cout << "\n\t\tERROR: bTree is empty.";
            }
            else {
                count(root, counts);
                cout << "\n\t\tAll " << counts << " nodes/leaves have been destroyed.";
                deleteEntireTree(root);
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}

