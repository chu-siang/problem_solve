#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e5+5;
pair<int,int> p[MAXN];

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

signed main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p,p+n,cmp);
    int cnt = 0;
    set<pair<int,int>>st;
    for(int i = 0; i < n; i++){
        if(st.size() == 0){
            st.insert({p[i].second*(-1),i});
            cnt++;
        }else{
            auto c = st.lower_bound({p[i].first*-1,-1});
            if(c != st.end()){
                st.erase(c);
                st.insert({p[i].second*-1,i});
                cnt++;
            }else if(c == st.end() && st.size() < k){
                st.insert({p[i].second*-1,i});
                cnt++;
            }
        }
    }
    cout << cnt ;
}