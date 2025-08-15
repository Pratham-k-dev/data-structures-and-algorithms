#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int x):val(x) , left(nullptr), right(nullptr){}
};

int ceil(Node* root,int x){
    Node* temp=root;
    int ans=-1;
    // int f=0;
   while(temp!=nullptr){
    if(temp->val==x){
        
        ans=x;
        break;
    }
    if(temp->val > x){ 
        
        ans=temp->val;
        temp=temp->left;
    
    }
    else{ temp=temp->right;
    
    }

   }
   return ans;
   
    
}
int floor(Node* root,int x){
    

    Node* temp=root;
    int ans=-1;
    
   while(temp!=nullptr){
    if(temp->val==x){
        
        ans=x;
        break;
    }
    if(temp->val > x){ 
        temp=temp->left;
        
    }
    else {
        
        
        ans=temp->val;
        temp=temp->right;
    
    }

   }
    return ans;
   
    

}
Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key); // If tree/subtree is empty, insert here

    if (key < root->val)
        root->left = insertBST(root->left, key); // Go left
    else if (key > root->val)
        root->right = insertBST(root->right, key); // Go right
    // If key == root->val, do nothing (assuming no duplicates)

    return root;
}
int main (){
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node* root=nullptr;
    for (int val : values) {
        root = insertBST(root, val);
    }
    cout<<ceil(root,5);
    return 0;
}