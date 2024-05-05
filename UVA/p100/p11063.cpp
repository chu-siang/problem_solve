#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 20005;
ll a[MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    ll c = 0;
    while(cin >> n){
        c++;
        bool flag = false;
        ll tmp,mod;
        memset(a,0,sizeof(a));
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] < 1) flag=true;
            if(i !=0 && a[i] <= a[i-1])flag = true;
        }
        set<ll>st;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(a[i]+a[j] < 0){
                    flag = true;
                    break;
                }if(st.count(a[i]+a[j])){
                    flag = true;
                    break;
                }else st.emplace(a[i]+a[j]);
            }
            if(flag)break;
        }
        cout << "Case #" << c << ": ";
        if(!flag) cout << "It is a B2-Sequence.\n\n";
        else cout << "It is not a B2-Sequence.\n\n";
        
    }
    return 0;
}