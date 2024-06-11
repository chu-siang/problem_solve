#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+5;
int a[MAXN];
signed main(){
    int x1,x2,y1,y2;
    int t;
    a[0] = 0;
    for(int i = 1; i <= 2e5+5; i++){
        a[i] = a[i-1]+i;
    }
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        if(x1 + y1 > x2 + y2){
            swap(x1,x2);
            swap(y1,y2);
        }
        if(x1 + y1 == x2 + y2){
            ans = abs(x1-x2);
        }else{
            if(x1+y1 == 0)ans += a[x2+y2];
            else ans += a[x2+y2] - a[x1+y1-1];
            ans += abs(x2+y2-x1-y1);
            ans -= x1;
            ans -= y2;
        }
        cout << "Case " << i << ": " << ans << '\n';
    }
}