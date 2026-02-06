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


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal = levelOrder(root);
    
        for (int i = 0; i < traversal.size(); i++) {
            if (i % 2) {
                reverse(traversal[i].begin(), traversal[i].end());
            }
        }

        return traversal;
    }
};


class Solution_2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if (root == nullptr) {
            return ans; 
        }
        
        queue<TreeNode*> q; 
        q.push(root); 
        int flag = 1;

        while (!q.empty()) {
            int size = q.size(); 
            vector<int> level(size); 

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop(); 

                int ind = flag == 1 ? i : size - 1 - i;
                
                level[ind] = node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            flag *= -1;
            ans.push_back(level); 
        }
        return ans; 
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        return levelOrder(root);
    }
};

int main() {
    
    return 0;
}