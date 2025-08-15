#include<bits/stdc++.h>
using namespace std;
  
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
    TreeNode* prev;
public:
    Solution():prev(nullptr){}
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=nullptr;
        prev=root;
    }

    /*
    algo:

    cur's right attach to cur left's right most

    the shift left tree to right and set left to null


    the tree will be right skewed ultimately
    
    */
void flatten2(TreeNode* root) {
    TreeNode* cur = root;  // Start with the root node

    while (cur) {
        // If the current node has a left child, we need to reposition it
        if (cur->left) {
            TreeNode* prev = cur->left;

            // Find the rightmost node of the left subtree (i.e., predecessor)
            while (prev->right) {
                prev = prev->right;
            }

            // Connect the rightmost node of left subtree to current node's right subtree
            prev->right = cur->right;

            // Move the left subtree to the right side
            cur->right = cur->left;
            cur->left = nullptr;  // Set left child to null (as per flattened list requirement)
        }

        // Move to the next node (always go right in flattened list)
        cur = cur->right;
    }
}

};

int main (){
    
    return 0;
}