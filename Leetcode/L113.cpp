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

//T.C : The time complexity of the code is O(N), where N is the number of nodes in the binary tree. 
//This is because each node is visited exactly once during the recursive traversal.
//Note that I am ignoring the time taken to move the temp values to result - result.push_back(temp);
//S.C :  The space complexity is O(H) in the worst case, where H is the height of the binary tree. 
//This is due to the recursion stack during the depth-first search. In the worst case, 
//the recursion stack will have H function calls, where H is the height of the tree.
class Solution {
public:
    void collectPaths(TreeNode* root, int curr, vector<int>& temp, vector<vector<int>>& result) {
        if (!root)
            return;

        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL && root->val == curr) {
            result.push_back(temp);
        }
        
        collectPaths(root->left, curr - root->val, temp, result);
        collectPaths(root->right, curr - root->val, temp, result);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        
        vector<int> temp;
        collectPaths(root, sum, temp, result);
        return result;
    }
};


class Solution_2 {
public:
    void pathSum(TreeNode* root, int sum, int targetSum, vector<vector<int>> &res, vector<int> path) {
        if (!root) return;
            
        sum += root->val;
        path.push_back(root->val);

        if (!root->left && !root->right) {
            if (sum == targetSum) {
                res.push_back(path);
                return;
            }
            return;
        }
        
        pathSum(root->left,  sum, targetSum, res, path);
        pathSum(root->right, sum, targetSum, res, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;

        pathSum(root, 0, targetSum, res, path);

        return res;
    }
};

int main() {
    
    return 0;
}