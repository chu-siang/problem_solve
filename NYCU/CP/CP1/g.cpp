//gear changing
#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int MAXN = 1e4+5;
ld c[105];
ld d[105];
signed main(){
    int n,m;
    ld p;
    cin >> n >> m;
    cin >> p;
    for(int i = 0; i < n; i++)cin >> c[i];
    for(int i = 0; i < m; i++)cin >> d[i];
    p/=100.0;
    set<ld>st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            st.insert(c[i]/d[j]);
        }
    }
    ld curr = *st.begin();
    st.erase(curr);
    bool work = true;
    for(auto i : st){
        if(curr*p < i - curr){
            work = false;
        }
        curr = i;
    }
    if(work)cout << "Ride on!";
    else cout << "Time to change gears!";
}