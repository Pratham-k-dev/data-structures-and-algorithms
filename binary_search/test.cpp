// #include<bits/stdc++.h>
// using namespace std;
//   int p(int x,int b=10){
//         int c=1;
//         while(x--){
//             c=c*b;
//         }
//         return c;
//     }
// int findNthDigit(int n) {
//         int x=0;
//         int sum=0;
//         int i=0,t=1;
//         while(sum<n){
//             i++;
//             x=i*(9*t);
//             sum+=x;
//             t*=10;
//         }
//         sum-=x;
//         cout<<i<<endl;
//         n-=sum;    
//         cout<<sum<<' '<<n<<endl;
//         int k=(i?p(i-1):0)+(n/i)-1;
//         cout<<k<<endl;
//         n=n%i;
//         if(n==0) return k%10;

//         k++;
//             int c=i-n;
//             while(c--){
//                 k/=10;
//             }
//             cout<<k%10<<endl;
//             return k%10;
        
//     }

// int main (){
//    findNthDigit(10000);
// // int x=0;
// //         int sum=0;
// //         int i=0,t=1;
// //         int n=2;
// //         while(n--){
// //             i++;
// //             x+=i*(9*t);
// //             sum+=x;
// //             t*=10;
// //         }
// //         cout<<x<<' '<<sum;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

    int mr=0;
    bool pred(vector<int> &h,unordered_set<int> &st,int r){
        
        
        for(int i=0;i<h.size();i++){
            int j=h[i];
            int f=0;
            if(st.count(h[i])) f=1;
            while(j>=1 && j>=h[i]-r){
                if(st.count(j)) {
                    f=1;
                    break;
                }
                j--;
            }
            j=h[i];
            if(!f){
                 while(j<=mr && j<=h[i]+r){
                if(st.count(j)) {
                    f=1;
                    break;
                }
                j++;
            }
            }
            if(!f) return false;
        }
        return true;
    }

    int findRadius(vector<int>& h, vector<int>& ht) {
        // return 0; 
        int l=0,r=mr;
        unordered_set<int> st;
        for(int i:ht){ st.insert(i);
        mr=max(mr,i);
        }
        r=mr;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pred(h,st,mid)) r=mid-1;
            else l=mid+1;
        }
        return l;

    }

int main (){
    vector<int> a={282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    vector<int> b={823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    cout<<findRadius(a,b);
    
    return 0;
}