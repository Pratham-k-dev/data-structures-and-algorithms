#include<bits/stdc++.h>
using namespace std;
//  Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    struct Info{
        bool Isbst;
        int mini;
        int maxi;
        int len;
    };


    int ans=1;
    Info postorder(Node* root){
        if(!root){


            Info obj;
            obj.Isbst=true;
            obj.mini=INT_MAX;
            obj.maxi=INT_MIN;
            obj.len=0;
            return obj;
        }
        Info obj;
        Info l,r;
        bool x,y;
        l=postorder(root->left);
        r=postorder(root->right);
        
        if(!l.Isbst || !r.Isbst){
            obj.Isbst=false;
            return obj;
        } 
        if(root->data>=r.mini || root->data<=l.maxi) {
            obj.Isbst=false;
            return obj;
        }
        obj.len=1+l.len+r.len;
        
        ans=max(ans,obj.len);
        
         obj.mini=min(root->data,l.mini);
        obj.maxi=max(root->data,r.maxi);
        
        return obj;
        
        
        
    }
  public:
  Solution(){
      ans=1;
  }
    int largestBst(Node *root) {
    //    int mini,maxi,l;
       
       postorder(root);
       return ans;
       
    }
};

int main (){
    
    return 0;
}
