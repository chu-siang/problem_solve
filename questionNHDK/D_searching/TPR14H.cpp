#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(int a,int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,g1,g2,t;
    cin >> n >> g1 >> g2 >> t;
    vector<ll>v1(n),v2(n);
    ll atotal = 0, btotal = 0,ans = 8e9;
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> v2[i];
        btotal +=v2[i];
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    ll j = n;
    for(int i = 0; i <= n; i++){
        while(atotal + btotal >= t && j >= 0){
            ans = min(ans,i*g1+j*g2);
            if(j - 1 >= 0)btotal -= v2[j-1];
            j--;
        }
        if(i < n)atotal += v1[i];
    }
    if(ans == 8e9)cout << "-1";
    else cout << ans;
}