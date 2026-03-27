//https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int precidence(char c){//define precidence
        if(c=='^') return 6;
        if(c=='/') return 5;
        if(c=='*') return 5;
        if(c=='+') return 3;
        if(c== '-') return 3;
        return 0;
    }
    bool operand(char c){
        if(c>='0' && c<='9') return true;
        if(c>= 'a' && c<='z') return true;
        if(c>= 'A' && c<='Z') return true;
        return false;
        
    }
  
    string infixToPostfix(string& s) {
        // code here
        string exp;
        int n=s.size();
        int i=0;
        stack<char> op,var;
        while(i<n){
            if(operand(s[i])) {
                exp.push_back(s[i]);
            }
            else if(s[i]=='('){ // encountered '(' treatas higher precidence
                op.push(s[i]);
            }
            else if(s[i]==')'){// evalute every thing till opening encountered
                while(op.size() && op.top()!='('){
                    exp.push_back(op.top());
                    op.pop();
                }
                op.pop();
            }
            else if(op.size() && op.top()== '('){// any thing after '(' is higher precidence
                op.push(s[i]);
            }
            else if(op.size()==0 || (precidence(op.top()) < precidence(s[i])) || (s[i]=='^' && op.top()=='^')){ // push when higher precidence
                op.push(s[i]);
            }
            else if( precidence(op.top()) >= precidence(s[i])){ // pop while precidence is lower
                
                while(op.size() && op.top()!='(' && precidence(op.top()) >= precidence(s[i]) ){
                    exp.push_back(op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
            i++;
        }
        while(op.size()){// empty remaining stack
            exp.push_back(op.top()) ;
            op.pop();
        }
        return exp;
    }
};


int main (){
    Solution s;
    string ex="k/(l-j*u/a)";
    
    cout<<s.infixToPostfix(ex);
    
    return 0;
}