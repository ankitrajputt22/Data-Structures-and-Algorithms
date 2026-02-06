#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}; 

// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        int floor = -1;
        
        while (root) {
            if (root->data == x) {
                floor = x;
                break;
            }
            else if (root->data > x) {
                root = root->left;
            }
            else {
                floor = root->data;
                root = root->right;
            }
        }
        
        return floor;
    }
};

int main() {
    
    return 0;
}