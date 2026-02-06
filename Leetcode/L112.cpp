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

class Solution {
public:
    bool pathSum(TreeNode* root, int sum, int targetSum) {
        if (!root) return false;
            
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == targetSum) return true;
            return false;
        }
        
        bool l = pathSum(root->left,  sum, targetSum);
        bool r = pathSum(root->right, sum, targetSum);

        return l || r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root, 0, targetSum);
    }
};

int main() {
    
    return 0;
}