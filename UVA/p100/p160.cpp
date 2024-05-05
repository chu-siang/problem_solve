#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool prime(int n){
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0){
        if(n == 2 || n == 3 || n == 5 || n == 7) return true;
        else return false; 
    }
    for(int i = 11; i * i <= n; i+=2){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    ll n;
    vector<ll>v;
    for(int i = 2; i < 10000; i++){
        if(prime(i))v.push_back(i);
    }
    while(cin >> n,n){
        map<ll,ll>mp;
        for(int i = 2; i <= n; i++){
            ll idx = 0, tmp = i;
            while(tmp >= v[idx]){
                while(tmp % v[idx] == 0){
                    tmp/=v[idx];
                    mp[idx]++;
                }
                idx++;
            }
        }
        cout <<setw(3)<< n << "! =";
        int count = 0;
        for(auto i : mp) {
            if(count >= 15){
                cout << '\n';
                cout << "      ";
                count = 0;
            }
            cout  <<setw(3)<< i.second;
            count++;
        }
        cout << '\n';
    }

}
