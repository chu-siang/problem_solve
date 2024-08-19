#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 5e5+5;
int p[MAXN];
ll n,k;

bool check(int len){
    int cnt = 1;
    int l = 1, r = p[0] + len;
    for(int i = 0; i < n; i++){
        if(p[i] <= r)continue;
        cnt++;
        r = p[i]+len;
    }
    return cnt <= k;
}

int main(){
    //service plot, base station 
    cin >> n >> k;
    int num;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p,p+n);
    int l = 0,r = p[n-1]+1;
    while(r - l > 1){
        int mid = l+r >> 1;
        if(check(mid))r = mid;
        else l = mid;
    } 
    cout << r << '\n';
}