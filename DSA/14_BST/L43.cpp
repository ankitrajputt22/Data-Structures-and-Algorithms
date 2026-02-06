//Definition for a binary tree node in Leetcode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;
        while (true) {
            if (curr->val <= val) {
                if (curr->right == nullptr) {
                    curr->right = new TreeNode(val);
                    break;
                } 
                else {
                    curr = curr->right;
                }
            }
            else {
                if (curr->left == nullptr) {
                    curr->left = new TreeNode(val);
                    break;
                } 
                else {
                    curr = curr->left;
                }
            }
        }

        return root;
    }
};

int main() {
    
    return 0;
}