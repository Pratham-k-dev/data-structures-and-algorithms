#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void DFS(struct node* root, vector<int> &ans){
 
    if(! root ) return ;
    if(!root->left && !root->right) ans.push_back(root->data);
    DFS(root->left,ans);
    DFS(root->right,ans);
    
}
int main (){

    // node* root;

     node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->left->right = new node(7);

    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(8);
    vector<int> ans;
    node* temp=root;
    while(temp){
        ans.push_back(temp->data);
        if(!temp->left) temp=temp->right;
        else temp=temp->left;
    }
    ans.pop_back();
    
    DFS(root,ans);
    int it=ans.size();
    temp=root;
    while(temp){
        ans.push_back(temp->data);
        if(!temp->right) temp=temp->left;
        else temp=temp->right;
    }
    ans.pop_back();
    reverse(ans.begin()+it,ans.end());
    for(int &i: ans) cout<<i<<' ';
    return 0;
}