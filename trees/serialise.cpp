#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   string toString(int x ){
    string s;
    if(x==0){
        return "0";
    }
        while(x){
            s.push_back('0'+x%10);
            x/=10;
        }
    reverse(s.begin(),s.end());
        
        return s;
   }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp){

            ans.append(toString(temp->val));
            ans.append(",");

            }
            else ans.append("#,");

            if(temp){
                q.push(temp->left);
                q.push(temp->right);
            }


        }
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        TreeNode* root=nullptr;
        if(s[0]=='#') return root;
        int i=0;
        queue<TreeNode*>q;
        int t=0;
        while(s[i]!=','){
                t=10*t+(s[i]-'0');
                i++;
            }

    root =new TreeNode (t);
        q.push(root);
        int r=0;
   

    i++;
        while(i<s.size()){
            if(q.empty()) break;
            if(s[i]==','){
                i++;
             continue;
            }
            TreeNode* temp;
             temp=q.front();
            q.pop();
           
            int x=0;
            if(s[i]=='#'){
                i++;
                
            }
            else{
            while(s[i]!=','){
                x=10*x+(s[i]-'0');
                i++;
            }
           
                    temp->left=new TreeNode (x);
                    q.push(temp->left);

            }
                
       i++;
        if(s[i]=='#'){
                i++;
                
            }
            else{
            x=0;
            while(s[i]!=','){
                x=10*x+(s[i]-'0');
                i++;
            }
                temp->right=new TreeNode (x);
                    q.push(temp->right);
                    
                    
            }
        i++;

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
int main()
{
    TreeNode *root = new TreeNode(0);
    // root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // root->left->left = new TreeNode(4);

    // root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(6);

    // root->right->left->left = new TreeNode(7);

    Codec* ser = new Codec();
Codec* deser = new Codec();
string tree = ser->serialize(root);
TreeNode* ans = deser->deserialize(tree);
    cout << tree;

    return 0;
}