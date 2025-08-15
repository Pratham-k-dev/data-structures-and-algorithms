//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

#include<bits/stdc++.h>
using namespace std;
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node* succesor(Node* root,int key){
    Node* temp=root;
    Node* suc=nullptr;
    while(temp){
        if(temp->data <= key){
            temp=temp->right;
        }
        else{
            suc=temp;
            temp=temp->left;
        }
    }
    return suc;
}
Node* pred(Node* root,int key){
        Node* temp=root;
    Node* pre=nullptr;
    while(temp){
        if(temp->data < key){
            pre=temp;
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return pre;
}
 vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        
        Node* temp=root;
        
        
        Node* pr=nullptr;
        Node* s=nullptr;
        while(temp){
            if(temp->data== key) break;
            // prev=temp;
            if(temp->data>key){
                s=temp;
                
                temp=temp->left;}
            else if(temp->data<key){ 
                pr=temp;
                
                
                temp=temp->right;
            
                
            }
        }
       if(temp){
           
       Node* temp1=temp->left;
       while(temp1){
           pr=temp1;
           temp1=temp1->right;
       }
       temp1=temp->right;
       while(temp1){
           s=temp1;
           temp1=temp1->left;
       }
       } 
        
            return {pr,s};
        
        
        
        
    }

int main (){
// Node* root = new Node(17);

// root->left = new Node(7);
// root->right = new Node(19);

// root->left->left = new Node(6);
// root->left->right = new Node(10);

// root->right->left = new Node(18);
// root->right->right = new Node(24);

// root->left->left->left = new Node(5);
// root->left->right->left = new Node(9);
// root->left->right->right = new Node(14);

// root->right->right->right = new Node(26);

// root->left->left->left->left = new Node(4);
// root->left->right->right->left = new Node(16);

// root->left->left->left->left->left = new Node(1);


    
//     vector<Node*> a=findPreSuc(root,21);
//    if(a[0]) cout<<a[0]->data<<' ';
//    if(a[1] )cout<<a[1]->data;
bool x=(0<1);
cout<<x;
    return 0;
}