#include<bits/stdc++.h>
using namespace std;
class Solution {
       
    bool pred(vector<int> &h,vector<int> &ht,int r){//Binary search
        
        if(ht[0]-r>h[0]) return false;

        for(int i=1;i<ht.size();i++){
            auto it=upper_bound(h.begin(),h.end(),ht[i-1]+r);
            if(it !=h.end() && *upper_bound(h.begin(),h.end(),ht[i-1]+r)<ht[i]-r) return false;
        }
        if(ht.back()+r< h.back()) return false;
        return true;
      
    }
public:
    int findRadius(vector<int>& h, vector<int>& ht) {
         int l=0,r=1e9;
         sort(h.begin(),h.end());
         sort(ht.begin(),ht.end());
         
        
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pred(h,ht,mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }

    int findRadius2(vector<int>& houses, vector<int>& heaters) {//optimised
         
         
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int ans = 0;
        int j = 0; 
        
        for (int house : houses) {
            while (j + 1 < heaters.size() && abs(heaters[j+1] - house) <= abs(heaters[j] - house)) {
                j++;
            }
            ans = max(ans, abs(heaters[j] - house));
        }
        return ans;
    }

};

int main (){
    
    return 0;
}