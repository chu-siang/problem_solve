//10035

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a,b;
    while(cin >> a >> b){
        if(a == b && a == 0) break;
        if(a < b) swap(a,b);
        ll count = 0;
        ll car = 0;
        while(a){
            if(b%10 + a%10 + car >= 10){
                car = (b%10 + a%10 + car)/10;
                count++;
            }else{
                car = 0;
            }
            a/=10,b/=10;
        }
        if(count == 0)cout <<"No carry operation.\n";
        else if(count == 1)cout <<"1 carry operation.\n";
        else cout << count <<" carry operations.\n";
    }
}