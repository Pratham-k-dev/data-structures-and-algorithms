//https://leetcode.com/problems/lru-cache/
#include<bits/stdc++.h>
using namespace std;
// head<-> most recent ..... least recent <-> tail
struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(){}
    Node(int k, int v):key(k), val(v) {
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache { // doubly Linked list implementation
unordered_map<int, Node*> mp;
Node* head;
Node* tail; 
int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head =new Node(-1,-1);
       
        tail =new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
        
        
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

            Node* temp= mp[key];
            // detach where it is currecntly
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            // insert after head
            temp->next=head->next;
            temp->prev=head;
            temp->next->prev=temp;
            head->next=temp;

            return temp->val;



        
    }
    
    void put(int key, int value) {
        Node* temp=nullptr;
        if(mp.find(key) != mp.end()){// if key already exist
            temp= mp[key];
            temp->val= value;
            //detach
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            //insert before head
            temp->next=head->next;
            temp->prev=head;
            temp->next->prev=temp;
            head->next=temp;

            return ;
        }

         temp= new Node(key, value);
        
            // insert after head 
            temp->next=head->next;
            temp->prev=head;
            temp->next->prev=temp;
            head->next=temp;


        if(mp.size()>=cap){// if capacity is full

            // delete least recent (which is before tail) 
            Node* temp2= tail->prev;
            tail->prev=temp2->prev;
            temp2->prev->next=tail;

            mp.erase(temp2->key);
            delete temp2;// delete the unecessary node

        }
         mp[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {// my first method (constraint dependent)
    int sz;
    int cnt;
    int cap;
    int s;
    deque<pair<int,int>> dq; // key, value
    vector<int > valid; // valid time intance
    unordered_map<int,int> mp; // key, time
public:
    LRUCache(int cap): valid(2*1e5 , 1)  {
        
        this->cap=cap;
        sz=0;
        cnt=0;
        s=0;
        
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;


        valid[mp[key]]=0;
        int r=-1;
        if(mp[key]-s < dq.size())r= dq[mp[key] - s].second;
        
        mp[key]=cnt;
        dq.push_back({key,r});
        cnt++;
        return r;

        
    }
    
    void put(int key, int value) {
        while(dq.size() && valid[s] ==0 ){

        dq.pop_front();
        s++;
        } 
    // cout<<1;
        if(mp.find(key)!= mp.end()) {
            valid[mp[key]]=0;
            dq.push_back({key,value});
            mp[key]=cnt;
            cnt++;
            return;

        }
        
        if(sz< cap){
            dq.push_back({key,value});
            mp[key]=cnt;
            sz++;
        }
        else{
           
            auto p=dq.front();
            dq.pop_front();
            valid[s]=0;
            mp.erase(p.first);
            dq.push_back({key,value});
            mp[key]=cnt;
            
            s++;
        }
        cnt++;

        // dq.push_back({key,value});
        // for(auto x:dq) cout<<x.first<<' ';
        // cout<<endl;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main (){
    
    return 0;
}