#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_1 {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int lH = height(root->left);
        int rH = height(root->right);

        return 1 + max(lH, rH);
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int leftH = height(root->left);
        int rightH = height(root->right);

        if (abs(leftH - rightH) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right) return false;

        return true;
    }
};


class Solution_2 {
public:
    int help(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int lh = help(root->left);
        if (lh == -1) return -1;
        int rh = help(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return help(root) != -1;
    }
};

int main() {
    
    return 0;
}