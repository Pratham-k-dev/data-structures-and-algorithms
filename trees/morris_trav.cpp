#include<bits/stdc++.h>
using namespace std;

    // Tree Node
    class Node {
      public:
        int data;
        Node* left;
        Node* right;

        // Constructor to initialize a new node
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
    };


class MorrisTrav {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> a;          // Stores the inorder traversal result
        Node* cur = root;       // Start traversal from the root node

        while (cur) {
            // Case 1: If the current node has no left child
            if (!cur->left) {
                a.push_back(cur->data);  // Visit the node
                cur = cur->right;        // Move to the right subtree
            }
            else {
                // Case 2: Current node has a left child
                // Find the rightmost node in the left subtree (inorder predecessor)
                Node* temp = cur->left;
                while (temp->right && temp->right != cur) {
                    temp = temp->right;
                }

                if (!temp->right) {
                    // First visit: create a thread to the current node
                    temp->right = cur;
                    cur = cur->left;  // Move to left subtree
                }
                else {
                    // Second visit: thread already exists (time to visit current)
                    temp->right = nullptr;       // Remove the thread
                    a.push_back(cur->data);      // Visit the node
                    cur = cur->right;            // Move to right subtree
                }
            }
        }

     
     
     
        return a;
    }

    vector<int> preOrder(Node* root) {
        // code here
         vector<int> a;
        
        Node* cur=root;
        while(cur){
            
            if(!cur->left){
                a.push_back(cur->data);
                cur=cur->right;
            }
            else{
                Node* temp=cur->left;
                while(temp->right && temp->right !=cur) temp=temp->right;
                
                if(!temp->right){
                    a.push_back(cur->data);//only change is if no right found push cur
                    temp->right=cur;
                    cur=cur->left;
                }
                else{
                    
                    temp->right=nullptr;
                    cur=cur->right;
                }
                
            }
        }
        
        return a;
    }
};


int main (){
    
    return 0;
}