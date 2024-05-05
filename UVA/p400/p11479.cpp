#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5+5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    ll k = 0;
    ll a, b, c;
    while(k < t){
        k++;
        cin >> a >> b >> c;
        cout <<"Case " << k << ": ";
        if(a > b && a > c){
            swap(a,c);
            if(a > b) swap(a,b);
        }else if(b > a && b > c){
            swap(b,c);
            if(a > b)swap(a,b);
        }else {
            if(a > b) swap(a,b);
        }
        if(a + b <= c)cout << "Invalid\n";
        else if(a == b && b == c)cout << "Equilateral\n";
        else if(a == b || b == c || a == c)cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}
