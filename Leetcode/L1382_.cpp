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
 

//Simple approach using inordere tree traversal
//T.C : O(n)
//S.C : O(n)
class Solution_1 {
public:
    void inOrder(TreeNode* root, vector<int>& vec) {
        if(!root)
            return;
        
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);

    }

    TreeNode* construct(int l, int r, vector<int>& vec) {
        if(l > r)
            return NULL;
        
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(vec[mid]);

        root->left  = construct(l, mid-1, vec);
        root->right = construct(mid+1, r, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        int l = 0, r = vec.size()-1;

        return construct(l, r, vec);
    }
};


// DSW Algorithm - to do later

class DSW {
private:
    // Right rotate (clockwise rotation)
    TreeNode* rightRotate(TreeNode* root) {
        TreeNode* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }
    
    // Left rotate (counter-clockwise rotation)
    TreeNode* leftRotate(TreeNode* root) {
        TreeNode* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }
    
    // Convert BST to right-skewed linked list (vine)
    TreeNode* createVine(TreeNode* root) {
        TreeNode* pseudoRoot = new TreeNode(0); // Dummy node
        pseudoRoot->right = root;
        
        TreeNode* tail = pseudoRoot;
        TreeNode* current = pseudoRoot->right;
        
        while (current != nullptr) {
            if (current->left != nullptr) {
                TreeNode* temp = current;
                current = current->left;
                temp->left = current->right;
                current->right = temp;
                tail->right = current;
            } else {
                tail = current;
                current = current->right;
            }
        }
        
        return pseudoRoot->right;
    }
    
    // Count nodes in the tree
    int countNodes(TreeNode* root) {
        int count = 0;
        while (root != nullptr) {
            count++;
            root = root->right;
        }
        return count;
    }
    
    // Balance the vine using rotations
    TreeNode* balanceVine(TreeNode* root, int nodeCount) {
        int m = (1 << (int)(log2(nodeCount + 1))) - 1;
        TreeNode* newRoot = root;
        
        // First compression
        for (int i = 0; i < nodeCount - m; i++) {
            newRoot = leftRotate(newRoot);
            root = newRoot->right;
        }
        
        // Successive compressions
        while (m > 1) {
            m /= 2;
            TreeNode* current = newRoot;
            for (int i = 0; i < m; i++) {
                current = leftRotate(current);
                current = current->right;
            }
        }
        
        return newRoot;
    }

public:
    // Main DSW algorithm
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        // Step 1: Convert BST to right-skewed tree (vine)
        TreeNode* vine = createVine(root);
        
        // Step 2: Count nodes
        int n = countNodes(vine);
        
        // Step 3: Balance the vine
        return balanceVine(vine, n);
    }
    
    // Utility function to print tree (inorder)
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    
    // Utility function to get height
    int height(TreeNode* root) {
        if (root == nullptr) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
};

// Example usage
int main() {
    // Create a skewed BST: 1 -> 2 -> 3 -> 4 -> 5
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    
    DSW dsw;
    cout << "Original tree (inorder): ";
    dsw.inorder(root);
    cout << "\nOriginal height: " << dsw.height(root) << endl;
    
    TreeNode* balanced = dsw.balanceBST(root);
    
    cout << "Balanced tree (inorder): ";
    dsw.inorder(balanced);
    cout << "\nNew height: " << dsw.height(balanced) << endl;
    
    return 0;
}