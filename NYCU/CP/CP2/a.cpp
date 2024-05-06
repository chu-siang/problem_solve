//	Deathstar
#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int>v(n,0);
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            v[j] |= x;
        }
    }
    for(auto i : v)cout << i << ' ';
}