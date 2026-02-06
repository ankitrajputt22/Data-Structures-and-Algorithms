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
    bool traversal(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL) return true;
        else if (node1 == NULL && node2 != NULL) return false;
        else if (node1 != NULL && node2 == NULL) return false;
        else if (node1->val != node2->val) return false;

        bool leftT = traversal(node1->left, node2->left);
        bool rightT = traversal(node1->right, node2->right);

        return leftT && rightT;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal(p, q);
    }
};

int main() {
    
    return 0;
}