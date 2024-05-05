#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    set<ll>st;
    st.emplace(1);
    ll cnt = 0;
    for(set<ll>::iterator it =st.begin(); it != st.end(); it++){
        ++cnt;
        if(cnt == 1500) {
            cout << "The 1500'th ugly number is "<< *it << ".\n";
            return 0;
        }
        st.emplace(*it * 2);
        st.emplace(*it * 3);
        st.emplace(*it * 5);
    }
}