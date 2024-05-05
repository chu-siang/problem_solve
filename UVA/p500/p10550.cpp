#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5+5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll s,a,b,c;
    while(cin >> s >> a >> b >> c){
        if(s == a && a == b && b == c && a == 0)break;
        ll deg = 720;
        deg += ((s - a + 40)%40)*9;
        deg += 360;
        deg += ((b - a + 40)%40)*9;
        deg += ((b - c + 40)%40)*9;
        cout << deg << '\n';
    }
}
