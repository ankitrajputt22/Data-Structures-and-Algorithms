#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


vector<int> postOrder(Node* root) {
    vector<int> postorder;

    if (root == NULL){
        return postorder;
    }

    // Two stacks for iterative traversal
    // Push the root node onto the first stack
    // Iterative traversal to populate st2 with nodes in postorder
    // Get the top node from st1
    // Push the node onto st2
    // Push left child onto st1 if exists 
    // Push right child onto st1 if exists
    // Populate the postorder traversal vector by popping st2

    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()){
        root = st1.top();
        st1.pop();

        st2.push(root);

        if (root->left != NULL){
            st1.push(root->left);
        }
        if (root->right != NULL){
            st1.push(root->right);
        }
    }
    
    while (!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    newline1;

    // Creating a sample binary tree
    // Getting postorder traversal
    // Printing the postorder traversal result
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    cout << "Postorder traversal: ";
    printVector(result);

    newline2;

    return 0;
}