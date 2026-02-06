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


    stack<Node*> st;

    Node* curr = root;
    while (!st.empty() || curr != NULL){
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            } else {
                curr = temp;
            }
        }
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    newline2;

    return 0;
}