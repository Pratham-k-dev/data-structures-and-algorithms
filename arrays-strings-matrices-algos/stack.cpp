#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;


};

class Stack{
    public:
    struct node *top;
    Stack(){
       top= NULL;
        
    }
    
    void Push(int n){
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(top==NULL){
        top=ptr;
        top->data=n;
        top->next=nullptr;
    }
    else{
        ptr->data=n;
        ptr->next=top;
        top=ptr;

    }
    }
    void Pop(){
        struct node* temp=top;
        top=top->next;
        delete temp;


    }   
    

};



int main (){
    // stack<int> s1;

    Stack s1;
    s1.Push(3);
    // cout<<s1.top()<<endl;
    s1.Pop();
   
    
    return 0;
}