#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    struct node* left;
    struct node* right;
};

struct node* createNode(int x){
    struct node* temp;
    temp=new struct node;
    temp->left=nullptr;
    temp->right=nullptr;
    temp->val=x;
    return temp;
}

struct node* Insert(struct node* root,int x){
    if(root==nullptr){
        
        return ;
    }

    if(root->val<x){
        root->right=Insert(root->right,x);
    }
    else{
        root->left=Insert(root->left,x);
    }

    return root;
}

struct node* Findmin(struct node* root){
    if(root->left==nullptr) return root;

    return Findmin(root->left);
}

// struct node* Delete(struct node* root,int x){ //my stupid code

//     struct node *key=root, *prv=nullptr;
//     while(key!=nullptr){
//         if(key->val==x){
//             break;
//         }
//         prv=key;
//          if(key->val<x){
//             key=key->right;
//         }
//         else key=key->left;

        
//     }
//     if(key==root) return nullptr;

//     if(key->left==nullptr || key->right==nullptr){
//         if(key->left==nullptr){
//             if(prv->left==key){
//                 prv->left=key->right;
//             }
//             else{
//                 prv->right=key->right;
//             }
//         }
//         else{
//             if(prv->left==key){
//                 prv->left=key->left;
//             }
//             else{
//                 prv->right=key->left;
//             }

//         }

//         delete key;
//     }
//     else{

//         struct node* temp=Findmin(key->right);
//         key->val=temp->val;

//         // delete temp;
//     }




// }


struct node* Delete(struct node* root,int key){
    if(root==nullptr) return nullptr;

    if(key <root->val){
        root->left=Delete(root->left,key);
    }
    else if(key>root->val){
        root->right=Delete(root->right,key);
    }
    else{
            if(root->left==nullptr){
                struct node* temp=root->right;
                delete root;
                return temp;

            }
            else if(root->right==nullptr){
                struct node* temp=root->left;
                delete root;
                return temp;
            }
            else{
                struct node* min=Findmin(root->right);
                root->val=min->val;
                root->right=Delete(root->right,min->val);

            }


    }

    return root;


}

void Inorder(struct node* root){
    if(root==nullptr) return;
    

    Inorder(root->left);
    cout<<root->val<<' ';
    Inorder(root->right);

}

int main (){

    int arr[]={5,2,18,-4,3,21,19,25};
    int n=sizeof(arr)/sizeof(arr[0]);
    struct node* root=nullptr;
    for(int i=0;i<n;i++){
        root=Insert(root,arr[i]);
    }

    Inorder(root);
    cout<<endl;
    
struct node* temp=Findmin(root);

cout<<temp->val<<endl;
    
    return 0;
}