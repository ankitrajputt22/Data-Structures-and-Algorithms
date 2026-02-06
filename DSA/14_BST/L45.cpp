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
    void inorder(TreeNode* root, vector<int> &arr) {
        if (root == nullptr) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;

        inorder(root, arr);

        int smallest = 0;
        for (int i = 0; i < arr.size(); i++) {
            smallest++;
            if (smallest == k) {
                return arr[i];
            }
        }

        return -1;
    }
};




int main() {
    
    return 0;
}