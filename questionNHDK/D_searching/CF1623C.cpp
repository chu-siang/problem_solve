#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5+5;
int h[MAXN];
int n;
int l,r,ans = -1;
bool check(int x){
    vector<int> cur_h(h,h+n);
    for(int i = n-1; i >= 2; --i){
        if(cur_h[i] < x)return false;
        int d = min(h[i],cur_h[i]-x)/3;
        cur_h[i-1] += d;
        cur_h[i-2] += d*2;
    }
    return cur_h[0] >= x and cur_h[1] >= x;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)cin >> h[i];
        l = 0, r = *max_element(h,h+n);
        while(l <= r){
            int mid = l+r>>1;
            if(check(mid))ans = mid,l = mid + 1;
            else r = mid-1;
        }
        cout << ans << '\n';
    }
}