#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


// Definition for a binary tree node in Leetcode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && root->val != val) {
            root = (val < root->val) ? root->left : root->right;
        }
        return root;
    }
};


class Solution_2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return root;

        if (root->val == val) return root;
        else if (val > root->val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }
};

int main() {
    
    return 0;
}