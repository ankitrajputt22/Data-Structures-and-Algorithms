/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
    }
};
// @lc code=end



/*
Tc - O(n^2)
Sc - O(n)
*/
class Solution_1 {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int lH = height(root->left);
        int rH = height(root->right);

        return 1 + max(lH, rH);
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int leftH = height(root->left);
        int rightH = height(root->right);

        if (abs(leftH - rightH) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right) return false;

        return true;
    }
};


/*
Tc - O(n)
Sc - O(n)
*/

class Solution_2 {
public:
    int help(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int lh = help(root->left);
        if (lh == -1) return -1;
        int rh = help(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return help(root) != -1;
    }
};





