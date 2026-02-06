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
    int pathS(TreeNode* root, int t, long long s) {
        if (!root) return 0;
        int cnt = 0;

        s += root->val;
        if (s == t) cnt++;
        
        cnt += pathS(root->left, t, s);
        cnt += pathS(root->right, t, s);

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int cnt = pathS(root, targetSum, 0); //countPathsFromNode

        cnt += pathSum(root->left, targetSum);
        cnt += pathSum(root->right, targetSum);

        return cnt;
    }
};

int main() {
    
    return 0;
}