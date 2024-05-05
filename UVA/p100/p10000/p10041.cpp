#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 3e5;

ll s[MAXN] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n,m;
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        sort(s,s+n);
        int k = n/2;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += abs(s[i] - s[k]); 
        }
        cout << sum << '\n';
    }
}