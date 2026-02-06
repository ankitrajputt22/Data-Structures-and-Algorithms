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

    Node (int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    Node(int val, Node* l, Node* r) {
        data = val;
        left = l;
        right = r;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    Node* insertHelper(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (node->data < val) {
            node->right = insertHelper(node->right, val);
        }
        else{
            node->left = insertHelper(node->left, val);
        }
        return node;
    }

    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return;
        }
        
        if (root->data < val) {
            root->right = insertHelper(root->right, val);
        }

        else {
            root->left = insertHelper(root->left, val);
        }
    }

    Node* deleteHelper(Node* root) {
        if (root->left == nullptr) {
            return root->right;
        } 
        else if (root->right == nullptr) {
            return root->left;
        }

        Node* rightC = root->right;
        Node* connectNode = rightConnectionNode(root->left); // gives the rightmost node of left child to connect the disconnected right child 
        Node* connectNode->right = rightC;

        return root->left;
    }

    Node* rightConnectionNode(Node* node) {
        if (node->right == nullptr) {
            return node;
        }

        return rightConnectionNode(node->right);
    }

    void delete(int val) {
        if (!root) return root;
        if (root->data == val) {
            return deleteHelper(root);
        }

        Node* dummy = root;
        while (root != NULL) {
            if (root->data > key) {
                if (root->left != nullptr && root->left->data == val) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            } 

            else {
                if (root->right != nullptr && root->right->data == val) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        root = dummy;
    }




    void preorderHelper(Node* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void preorder() {
        preorderHelper(root);
    }
    void inorderHelper(Node* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }

    void inorder() {
        inorderHelper(root);
    }

    

};



 
int main() {
    BST b;
    b.insert(7);
    b.insert(14);
    b.insert(37);
    b.insert(3);
    b.insert(64);

    b.preorder();
    cout << endl;
    // b.inorder();
    // cout << endl;

    return 0;
}