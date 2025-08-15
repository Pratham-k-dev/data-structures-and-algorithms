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
int Height(node* root){
    if(root==nullptr) return 0;
        return 1+max(Height(root->left),Height(root->right));
}
bool brute_force(node* root){
    int lh=Height(root->left);
    int rh=Height(root->right);
    if(abs(lh-rh)>1) return false;
    if(!brute_force(root->left) || !brute_force(root->right)) return false;
    return true;

}
int height_opt(node* root){
    if(root==nullptr) return 0;
    int lh=height_opt(root->left);
    int rh=height_opt(root->right);
    if(abs(lh-rh)>1) return -1;
    if(lh==-1 ||rh==-1) return -1;
        return 1+max(lh,rh);
}
bool opt(node* root){
if(Height(root) >-1) return true;
        return false;
}
int main (){
    
    return 0;
}
