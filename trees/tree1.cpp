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
class DFS{
    public:
    void inorder(struct node* root){
        if(root == nullptr) return;
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
     void preorder(struct node* root){
        if(root == nullptr) return;
        cout<<root->data<<' ';
        inorder(root->left);
        inorder(root->right);
    }
     void postorder(struct node* root){
        if(root == nullptr) return;
        inorder(root->left);
        inorder(root->right);
        cout<<root->data<<' ';
    }

};

class iterativeDFS{
    public:
    void preorder(node* root){
        stack<node*> s;
        s.push(root);
        while(!s.empty()){
            node* curr=s.top();

            s.pop();

            cout<<curr->data<<' ';
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);

        }
    }
    void inorder(node* root){
        stack<node*> s;
        
        node* temp=root;
        while(true){
            if(temp!=nullptr){
                s.push(temp);
                temp=temp->left;
            }
            else{
                if(s.empty()) break;
                temp= s.top();
                s.pop();
                cout<<temp->data<<' ';
                temp=temp->right;

            }
        }
    }

    void postorder_2Stack(node* root){
        stack<node*> s;
        stack<int> st;
        s.push(root);
        while(!s.empty()){
            node* curr=s.top();
            st.push(curr->data);
            s.pop();

            
            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);

        }
        while(!st.empty()){
            cout<<st.top()<<' ';
            st.pop();
        }
    }
    void postorder_1Stack(node* root){//not correct yet
        stack<pair<node*,bool>> s;
        s.push({root,0});
        node* curr=root;
        while(!s.empty() ||curr !=nullptr ){
            if(curr !=nullptr) {
                if(curr)
                s.push({curr,0});
                curr=curr->left;

            }
            else{
                node* temp=s.top().first->right;
                // curr=temp;
                if(temp == nullptr){
                    temp=s.top().first;
                    s.pop();
                    // if(!s.empty()) curr=s.top()->right;
                    cout<<temp->data<<' ';
                    while(!s.empty() && temp==s.top().first->right){
                        temp=s.top().first;
                        s.pop();
                    // curr=temp;
                    //  if(!s.empty()) curr=s.top()->right;
                    cout<<temp->data<<' ';
                    }

                }
                else{
                    curr=temp;
                }
            }
        }
        
    }

    void postorder_1stack(node* root) {
    if (root == nullptr) return;

    stack<node*> s;
    node* curr = root;
    node* lastVisited = nullptr;

    while (!s.empty() || curr != nullptr) {
        if (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        } else {
            node* peekNode = s.top();
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                // go right only if right child exists and hasn't been visited
                curr = peekNode->right;
            } else {
                cout << peekNode->data << ' ';
                lastVisited = peekNode;
                s.pop();
            }
        }
    }
}

};

void BFS(struct node* root){//level order
    queue<struct node*> q;
    q.push(root);
    
    
    while(!q.empty()){
          struct node* curr = q.front();
        q.pop();

        // Print current node's data
        cout << curr->data << ' ';

        // Push left and right children if they exist
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    
}

vector<vector<int>> bfs(struct node* root){// returning level orders of each level
    vector<vector<int>> ans;

    if(root==nullptr)  return ans;
    queue<node*> q; 
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            struct node* curr= q.front();
            temp.push_back(curr->data);
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        ans.push_back(temp);
    }
    return ans;
}



int main (){
    struct node* root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    DFS trav;
    // trav.inorder(root);
    cout<<endl;
    // BFS(root);
    vector<vector<int>> lev=bfs(root);
    // cout<<"level order: "<<endl;
    // for(auto i:lev){
    //     for(int j:i) cout<<j<<' ';
    //     cout<<endl;
    // }

    iterativeDFS trav2;
    // trav2.inorder(root);
    // trav2.postorder_2Stack(root);
    cout<<endl;
    trav2.postorder_1stack(root);


    
    
    return 0;
}
