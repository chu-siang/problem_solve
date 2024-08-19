#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+5;
pair<int,int> p[MAXN];

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n,cmp);
    int buy = 0;
    int price = 0;
    int l = 0, r = n-1;
    int t;
    while(l <= r){
        if(p[l].second > buy){
            t = min(p[r].first,p[l].second-buy);
            price += 2*t;
            buy+=t;
            p[r].first-=t;
        }else{
            t = p[l++].first;
            price += t;
            buy+=t;
        }
        if(p[r].first == 0)r--;
    }
    cout << price;
}
