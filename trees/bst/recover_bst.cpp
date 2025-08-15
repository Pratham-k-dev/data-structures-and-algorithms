//https://leetcode.com/problems/recover-binary-search-tree/?envType=problem-list-v2&envId=tree

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    TreeNode* prev = nullptr;  // keeps track of the previously visited node in inorder
    TreeNode* f = nullptr;     // first node that violates BST property
    TreeNode* p1 = nullptr;    // second node that violates BST property
    int fl = 0;                // flag to stop recursion early once swapped

public:
    void recoverTree(TreeNode* root) {
        // perform inorder traversal to detect swapped nodes
        inorder(root);

        // if swap wasn't already performed in recursive step, do it now
        if (!fl) {
            swap(f->val, p1->val);
        }
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        // recurse left
        inorder(root->left);

        // check for violation of BST property (inorder should be sorted)
        if (prev) {
            if (root->val < prev->val && !f) {
                // first violation: record both nodes
                f = prev;
                p1 = root;
            }
            else if (root->val < prev->val && f) {
                // second violation: swap immediately and stop
                swap(root->val, f->val);
                fl++;  // set flag to indicate swap has happened
                return;
            }
        }

        prev = root;  // update prev before going right

        // recurse right
        inorder(root->right);
    }
};


int main (){
    
    return 0;
}