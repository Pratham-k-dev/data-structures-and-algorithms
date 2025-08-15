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

class PreAndIn {
    void construct(TreeNode* &root,vector<int>& pre, vector<int>& in,int i,int j,int l,unordered_map<int,int> &mi){
        if(l<=0||i<0 || i>=pre.size()) return ;
        
       int val=pre[i];
        root=new TreeNode(val);
       
       
       
        int lleft=mi[pre[i]]-j;
        int lright=l-lleft-1;
        if(lleft>0) construct(root->left,pre,in,i+1,j,lleft,mi);
        if(lright>0) construct(root->right,pre,in,i+lleft+1,mi[pre[i]]+1,lright,mi);
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        unordered_map<int,int> mi;
        for(int i=0;i<in.size();i++) mi[in[i]]=i;
        TreeNode* root=nullptr;
        construct(root,pre,in,0,0,pre.size(),mi);
        return root;

    }
};
  


class PostAndIn {
    void construct(TreeNode* &root,vector<int>& po, vector<int>& in,int i,int j,int l,unordered_map<int,int> &mi){
        if(l<=0||i<0 || i>=po.size()) return ;
        
       int val=po[i];
        root=new TreeNode(val);
       
       
       
        int lleft=mi[po[i]]-j;
        int lright=l-lleft-1;
        if(lleft>0) construct(root->left,po,in,i+lright+1,j,lleft,mi);
        if(lright>0) construct(root->right,po,in,i+1,mi[po[i]]+1,lright,mi);
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        unordered_map<int,int> mi;
        for(int i=0;i<in.size();i++) mi[in[i]]=i;
        TreeNode* root=nullptr;
        reverse(po.begin(),po.end());
        construct(root,po,in,0,0,po.size(),mi);
        return root;
    }
};

int main (){
    
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define tc() ll t; cin>>t; while(t--)
using namespace std;

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
    
    return 0;
}