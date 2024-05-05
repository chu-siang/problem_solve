#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll x,y,ans;

void square(int i,int j,int k){
    if(k == 0) return ;
    if(x >= i - k && x <= i + k && y <= j + k && y >= j - k) ans++;
    square(i-k,j-k,k/2);
    square(i-k,j+k,k/2);
    square(i+k,j+k,k/2);
    square(i+k,j-k,k/2);
}

int main(){
    ll k;
    while(cin >> k >> x >> y){
        if(x == y && y == k && k == 0)break;
        ans = 0;
        square(1024,1024,k);
        cout << setw(3) << ans << '\n';
    }
}
/*A 183-5724 17 58 18 04*/