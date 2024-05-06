//uva10783
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin >> t;
    for(int i = 1; i <= t;i++){
        ll a,b;
        cin >> a >> b;
        ll sum = 0;
        if(!(a&1))a++;
        if(!(b&1))b--;
        for(int j = a; j<= b; j+=2){
            sum += j;
        }
        cout << "Case " << i <<": "<<sum << '\n';
    }
   
    return 0;
}