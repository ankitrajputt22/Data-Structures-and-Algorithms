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

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil = -1;
        
        while (root) {
            if (root->data == x) {
                ceil = root->data;
                return ceil;
            }
            
            if (x > root->data) {
                root = root->right;
            } 
            else {
                ceil = root->data;
                root = root->left;
            }
        }
        
        return ceil;
    }
};


int main() {
    
    return 0;
}