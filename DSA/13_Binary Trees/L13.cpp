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


vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;

    if (root == NULL) {
        return {};
    }

    stack<pair<Node*, int>> st;

    // Start with the root node and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            // Store the node's data in the preorder traversal
            pre.push_back(it.first->data);

            // Move to state 2 (inorder) for this node
            it.second = 2;

            // Push the updated state back onto the stack
            st.push(it); 

            // Push left child onto the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        else if (it.second == 2) {
            // Store the node's data in the inorder traversal
            in.push_back(it.first->data);

            // Move to state 3 (postorder) for this node
            it.second = 3;

            // Push the updated state back onto the stack
            st.push(it); 

            // Push right child onto the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        else {
            // Store the node's data in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);

    return result;
}



void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    newline1;
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    newline2;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    newline2;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    newline2;

    return 0;
}