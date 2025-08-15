#include<bits/stdc++.h>
using namespace std;

int main (){//insertion, deletion in logn
    set<int> st; // store in sorted and without duplicates

    st.insert(1);
    st.insert(2);
    st.insert(5);
    st.insert(3);

    auto it=st.find(3); //returns iterator //if not found return st.end()
    //st.erase(3); //st.count(2)
    //st.erase(it1,it2);// it1 included it2 not



        // s.upper_bound=bigger than that no.
    //  s.lower_bound=that no. or bigger

    // cout<<*st.lower_bound(3);



    //unordered_set    //mostly o(1) worst case o(n)



    return 0;
}