#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];

signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    vector<int>tmp;
    for(int i = 0; i < n; i++){
        int idx =  lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
        if(idx == tmp.size())tmp.push_back(a[i]);
        else tmp[idx] = a[i];
    }
    cout << tmp.size();
}