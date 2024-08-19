#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int>v(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >>v[i];
        sum += v[i];
    }
    sort(v.begin(),v.end());
    cout << max(sum,v[n-1]*2);
}