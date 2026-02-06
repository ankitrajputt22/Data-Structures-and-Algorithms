/*
Time Complexity:
Search, Insert, Delete: O(h) where h is height
Balanced BST: O(log n)
Worst-case (skewed): O(n)

Key Features:
Insertion: Maintains BST property
Search: Efficient O(h) search
Deletion: Handles all three cases (no child, one child, two children)
Traversals: Inorder, Preorder, Postorder
Height calculation: Returns tree height

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    TreeNode* root;
    
    TreeNode* insertRec(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            root->left = insertRec(root->left, val);
        } else if (val > root->val) {
            root->right = insertRec(root->right, val);
        }
        
        return root;
    }
    
    bool searchRec(TreeNode* root, int val) {
        if (root == nullptr) return false;
        if (root->val == val) return true;
        
        return val < root->val ? searchRec(root->left, val) : searchRec(root->right, val);
    }
    
    TreeNode* deleteRec(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        
        if (val < root->val) {
            root->left = deleteRec(root->left, val);
        } else if (val > root->val) {
            root->right = deleteRec(root->right, val);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            // Node with two children: get inorder successor
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteRec(root->right, temp->val);
        }
        
        return root;
    }
    
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    void inorderRec(TreeNode* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->val << " ";
            inorderRec(root->right);
        }
    }
    
    void preorderRec(TreeNode* root) {
        if (root != nullptr) {
            cout << root->val << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }
    
    void postorderRec(TreeNode* root) {
        if (root != nullptr) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->val << " ";
        }
    }
    
    int heightRec(TreeNode* root) {
        if (root == nullptr) return -1;
        return 1 + max(heightRec(root->left), heightRec(root->right));
    }
    
public:
    BST() {
        root = nullptr;
    }
    
    void insert(int val) {
        root = insertRec(root, val);
    }
    
    bool search(int val) {
        return searchRec(root, val);
    }
    
    void remove(int val) {
        root = deleteRec(root, val);
    }
    
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    
    void preorder() {
        preorderRec(root);
        cout << endl;
    }
    
    void postorder() {
        postorderRec(root);
        cout << endl;
    }
    
    int height() {
        return heightRec(root);
    }
    
    bool isEmpty() {
        return root == nullptr;
    }
};

int main() {
    BST bst;
    
    // Insert values
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values) {
        bst.insert(val);
    }
    
    // Tree structure:
    //       50
    //     /    \
    //    30     70
    //   /  \   /  \
    //  20  40 60  80
    
    cout << "Inorder traversal: ";
    bst.inorder();  // Output: 20 30 40 50 60 70 80
    
    cout << "Preorder traversal: ";
    bst.preorder(); // Output: 50 30 20 40 70 60 80
    
    cout << "Postorder traversal: ";
    bst.postorder(); // Output: 20 40 30 60 80 70 50
    
    // Search operations
    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found") << endl; // Found
    cout << "Search 90: " << (bst.search(90) ? "Found" : "Not found") << endl; // Not found
    
    // Delete operations
    bst.remove(20); // Delete leaf node
    cout << "After deleting 20: ";
    bst.inorder(); // 30 40 50 60 70 80
    
    bst.remove(30); // Delete node with one child
    cout << "After deleting 30: ";
    bst.inorder(); // 40 50 60 70 80
    
    bst.remove(50); // Delete node with two children
    cout << "After deleting 50: ";
    bst.inorder(); // 40 60 70 80
    
    // Height
    cout << "Tree height: " << bst.height() << endl;
    
    return 0;
}