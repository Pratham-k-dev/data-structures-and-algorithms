//Deque process

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
    tc(){
        int n;
        cin>>n;
        vi a(n);
        for(int &i: a)cin>>i;
        int prev=0;
        int i=0,j=n-1;
       string s; 
       
        while(i<=j){
            if(i==j){
                s.append("L");
                break;
            }
            if(i<=j && a[i]>prev && a[j]>prev){
                if(a[i]>a[j]){
                    s.append("LR");
                    prev=a[j];
                    i++;
                    j--;
                }
                else{
                   s.append("RL");
                    prev=a[i];
                    i++;
                    j--; 
                }
            }
            else if(i<=j && a[i]<prev && a[j]<prev){
                 if(a[i]>a[j]){
                    s.append("RL");
                    prev=a[i];
                    i++;
                    j--;
                }
                else{
                    s.append("LR");
                    prev=a[j];
                    i++;
                    j--;

                }
            }

            if(i<=j && a[i]<prev && a[j]>prev){
                s.append("RL");
                prev=a[i];
                i++;
                j--;
            }
            else if(i<=j && a[i]>prev && a[j]<prev){
                s.append("LR");
                prev=a[j];
                i++;
                j--;
            }
        }

        cout<<s<<endl;
    }
    return 0;
}