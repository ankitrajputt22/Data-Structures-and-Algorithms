#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Definition for a binary tree node in Leetcode
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
    TreeNode* findRightConnectionNode(TreeNode* root) {
        if (root->right == nullptr) {
            return root;
        }

        return findRightConnectionNode(root->right);
    }
    
    TreeNode* helper(TreeNode* root) {
        if (root->right == nullptr) return root->left;
        else if (root->left == nullptr) return root->right;

        TreeNode* rightChild = root->right;
        TreeNode* connectionNode = findRightConnectionNode(root->left);

        connectionNode->right = rightChild;
        
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } 
            else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};

int main() {
    
    return 0;
}