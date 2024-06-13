#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //constructor for the node class
    Node(string i, Node* l, Node* r) {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree {
public:
    Node* ROOT;

    BinaryTree() {
        ROOT = nullptr; //initializing ROOT to NULL
    }

    void insert(string element) //insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); //allocate memory for the new node
        newNode->info = element; //assign value to the data of the new node
        newNode->leftchild = nullptr; // make the left child of the new node point to NULL
        newNode->rightchild = nullptr; // make the right child of the new node point to NULL

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //Locate the node which will be the parent of

        if(parent == nullptr) { //if the parent is null, tree is empty
            ROOT = newNode; //mark the new node as ROOT //step 5a
            return;
        }
        
        if(element < parent->info) //if the value in the data field of the new node is less than  that of parent:
        {
            parent->leftchild = newNode; //Make the left child of parent point to the new node
        }
        else if(element > parent->info) //If the value in the data field of the new node is greater than that of the parent:
        {
            parent->rightchild = newNode; //Make the right child of parent point to the new node
        }
    }
};