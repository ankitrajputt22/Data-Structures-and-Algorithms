#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

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
    int height(TreeNode* node) {
        if (node == nullptr) return 0;

        int lh = height(node->left);
        int rh = height(node->right);
        return max(lh, rh) + 1;
    }

    void helper(TreeNode* node, int& maxi) {
        if (node == nullptr) return;

        int lH = height(node->left);
        int rH = height(node->right);

        maxi = max(lH + rH, maxi);  // edges = left + right

        helper(node->left, maxi);
        helper(node->right, maxi);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        helper(root, maxi);

        return maxi;
    }
};


class Solution_2 {
public:
    int height(TreeNode* root, int &ans) {
        if (root == nullptr) return 0;
        
        int leftH = height(root->left, ans);
        int rightH = height(root->right, ans);

        ans = max(ans, leftH + rightH);

        return 1 + max(leftH, rightH);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;

        int h = height(root, ans);
        return ans;
    }
};

int main() {
    
    return 0;
}