#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,a1;
    cin >> n >> m >> a1;
    int temp;
    int gcd = 0,num = 0;
    for(int i = 1; i < n; i++){
        cin >> temp;
        if(i == 1){
            num = (temp > a1 ? temp - a1 : a1 - temp);
        }
        num = __gcd(num,(temp > a1? temp - a1 : a1 - temp));
    }
    for(int i = 0; i < m; i++){
        cin >> temp;
        cout << __gcd(a1+temp,num) << ' ';
    }

}
