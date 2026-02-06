#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*
🔍 Algorithm Explanation:
Top View of Binary Tree - This solution uses a level-order traversal approach with horizontal distance tracking.

Key Concepts:
Horizontal Distance: Root = 0, left child = parent-1, right child = parent+1
Map: Stores the first node encountered at each horizontal distance
Queue: For level-order traversal with (node, horizontal_distance) pairs

Time Complexity: O(N log N) - due to map operations
Space Complexity: O(N) - for queue and map storage
*/


class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int,int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
         
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            if (mpp.find(line) == mpp.end()) 
                mpp[line] = node->data;
                
            if (node->left != NULL) {
                q.push({node->left, line-1});
            }
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }
        
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}