#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {} 

    // Node(int val) {
    //     data = val;
    //     left = right = nullptr;
    // }
};

// Function to perform preorder traversal of the tree and store values in 'arr
void preorder(Node* root, vector<int> &arr){
    // If the current node is NULL (base case for recursion), return
    if (root == nullptr){
        return;
    }

    // Push the current node's value into the vector
    arr.push_back(root->data);
    
    // Recursively traverse the left subtree
    preorder(root->left, arr);

    // Recursively traverse the right subtree
    preorder(root->right, arr);
}

// Function to initiate preorder traversal and return the resulting vector
vector<int> preOrder(Node* root){
    // Create an empty vector to store preorder traversal values
    vector<int> arr;

    // Call the preorder traversal function
    preorder(root, arr);

    // Return the resulting vector containing preorder traversal values
    return arr;
}


int main() {
    newline1;

    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";

    // Output each value in the  preorder traversal result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    newline2;

    return 0;
}