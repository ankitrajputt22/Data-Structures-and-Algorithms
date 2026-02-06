#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        
  
        if (root == nullptr) {
            return inorder;
        }
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (!st.empty() || node != NULL) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop(); 
                inorder.push_back(node->val);
                node = node->right;
            }
        }

        // while (true) {
        //     if (node != nullptr) {
        //         st.push(node);
        //         node = node->left;
        //     }
        //     else {
        //         if (st.empty() == true) break;
        //         node = st.top();
        //         st.pop();
        //         inorder.push_back(node->val);
        //         node = node->right;
        //     }
        // }
        
        return inorder;
    }
};

int main() {
    newline1;

    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    newline2;

    return 0;
}