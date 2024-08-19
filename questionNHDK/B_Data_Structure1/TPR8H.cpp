#include<iostream>
#include<map>
using namespace std;

int x [2000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int n;
    cin >> t;
    while(t--){
        map<int,int>mp;
        cin >>n;
        for(int i = 0; i < n; i++){
            cin >> x[i];
            mp[x[i]] = 0;
        }
        int cnt = 0;
        for(auto &it : mp)
            it.second = ++cnt;
        for(int i = 0; i < n; i++){
            cout << mp[x[i]] << " ";
        }
        cout << '\n';
    }
}

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(),b.end());
        b.resize(unique(b.begin(),b.end())-b.begin());
        for(int i = 0; i < n; i++){
            a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
        }
        for(auto i : a)
            cout << i << ' ';
        cout << '\n';
    }
}
*/