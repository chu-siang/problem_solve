//uva 10550
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll start,n1,n2,n3;
    while(cin >> start >> n1>> n2>>n3){
        int ans = 720;
        ans +=((start - n1 + 40) % 40) * 9;
        ans += 360;
        ans +=((n2 - n1 + 40) % 40) * 9;
        ans += ((n2-n3+40)%40)*9;
        cout << ans << '\n';
    }
}