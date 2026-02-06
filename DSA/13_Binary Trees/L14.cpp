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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if (root == nullptr) {
            return ans; 
        }
        
        queue<TreeNode*> q; 
        q.push(root); 

        while (!q.empty()) {
            int size = q.size(); 
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop(); 

                level.push_back(node->val); 

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(level); 
        }

        return ans; 
    }


    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        vector<vector<int>> ans = levelOrder(root);
        return ans.size();
    }
};


class Solution_2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};

int main() {
    
    return 0;
}