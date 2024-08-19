#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int b[MAXN];
int lob[MAXN],ap[MAXN];
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        lob[b[i]] = i;
    }
    for(int i = 0; i < n; i++){
        ap[i] = lob[a[i]];
    }
    vector<int>tmp;
    for(int i = 0; i < n; i++){
        int idx =  lower_bound(tmp.begin(),tmp.end(),ap[i])-tmp.begin();
        if(idx == tmp.size())tmp.push_back(ap[i]);
        else tmp[idx] = ap[i];
    }
    cout << tmp.size();
}