#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5;
ll arr[MAXN]={0};

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < MAXN; i++){
        arr[i] = arr[i-1]+i;
    }
    for(int Case = 1; Case <= n; Case++){
        ll ans = 0;
        ll a,b,x,y;
        cin >> a >> b >> x >> y;
        if(a + b > x + y)swap(a,x),swap(b,y);
        else if(a + b == x + y){
            if(y < b) swap(a,x),swap(b,y);
        }
        ll cnt1 = 0,cnt2 = 0;
        if(x+y == 0){
            cnt2 = 0;
        }else cnt2 = arr[x+y-1]+x+y+x;
        // 上面一個點 下面一個點
        if(a+b == 0){
            cnt1 = 0;
        }else cnt1 = arr[a+b-1]+a+b+a;
        ans = (cnt2 - cnt1);
        cout << "Case " << Case << ": " << ans << '\n';
    }
    
}