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
    int maxPathSum(TreeNode* root) {
        if (!root) return INT_MIN;
        
        int throughRoot = root->val;
        if (root->left) throughRoot += max(0, maxPathFrom(root->left));
        if (root->right) throughRoot += max(0, maxPathFrom(root->right));
        
        int leftMax = maxPathSum(root->left);
        int rightMax = maxPathSum(root->right);
    
        return max(throughRoot, max(leftMax, rightMax));
    }
    
    int maxPathFrom(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, maxPathFrom(node->left));
        int right = max(0, maxPathFrom(node->right));
        return node->val + max(left, right);
    }
};


class Solution_2 {
public:
    // int pathSum(TreeNode* node) {
    //     if (node == nullptr) return 0;
    //     if (node->left == NULL && node->right == NULL) return node->val;

    //     // int lS = max(0, pathSum(node->left));
    //     // int rS = max(0, pathSum(node->right));
    //     int lS = pathSum(node->left);
    //     int rS = pathSum(node->right);

    //     return max(lS, rS);
    // }

    // void helper1(TreeNode* node, int& maxSum) {
    //     if (node == nullptr) return ;
    
    //     // int lS = pathSum(node->left);
    //     // int rS = pathSum(node->right);
    //     int lS = max(0, pathSum(node->left));
    //     int rS = max(0, pathSum(node->right));

        
    //     maxSum = max(lS + rS + node->val, maxSum);

    //     helper(node->left, maxSum);
    //     helper(node->right, maxSum);
    // }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;

        int maxPathSum = INT_MIN;
        helper2(root, maxPathSum);

        return maxPathSum;
    }   

    int helper2(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        int lS = max(0, helper2(node->left, maxSum));
        int rS = max(0, helper2(node->right, maxSum));

        maxSum = max(lS + rS + node->val, maxSum);
        
        return node->val + max(lS, rS);
    }
};


int main() {
    
    return 0;
}