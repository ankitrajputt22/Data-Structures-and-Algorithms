#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

// Definition for a binary tree node in Leetcode
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
    
    int floor(TreeNode* root, int x) { // val <= queries[i]
        int floor = -1;
        while (root) {
            if (root->val == x) {
                floor = x;
                break;
            }
            else if (root->val > x) {
                root = root->left;
            }
            else {
                floor = root->val;
                root = root->right;
            }
        }

        return floor;
    }

    // val >= queries[i]
    int ceil(TreeNode* root, int x) { 
        int ceil = -1;
        while (root) {
            if (root->val == x) {
                ceil = x;
                break;
            }
            else if (root->val < x) {
                root = root->right;
            }
            else {
                ceil = root->val;
                root = root->left;
            }
        }

        return ceil;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> ans(n, vector<int>(2));


        for (int i = 0; i < n; i++) {
            ans[i][0] = floor(root, queries[i]);
            ans[i][1] = ceil(root, queries[i]);
        }

        return ans;
    }
};


class Solution_2 {
public:
    void inorder(TreeNode* root, vector<int> &vec) { // inorder traversal in BST gives sorted array
        if (root == nullptr) {
            return;
        }

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    int ceil(vector<int>& arr, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        return it != arr.end() ? *it : -1;
    }

    int floor(vector<int>& arr, int x) {
        auto it = upper_bound(arr.begin(), arr.end(), x);
        return it == arr.begin() ? -1 : *(it - 1);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> ans;
        
        vector<int> arr;
        inorder(root, arr);

        for (int i = 0; i < n; i++) {
            int ce = ceil(arr, queries[i]);
            int fl = floor(arr, queries[i]);

            ans.push_back({fl, ce});
        }
        
        return ans;
    }
};


int main() {
    
    return 0;
}