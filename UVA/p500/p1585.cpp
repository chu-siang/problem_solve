#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    string s1,s2,s;
    ll t;
    int arr[81];
    arr[0] = 0;
    for(ll i = 1; i < 80; i++)arr[i] = arr[i-1]+i;
    cin >> t;
    ll n;
    while(t--){
        cin >> s;
        int len = s.length();
        int a = 0;
        ll sum = 0;
        for(int i = 0; i < len; i++){
            if(s[i] =='O')a++;
            if(s[i] == 'X')sum+= arr[a], a = 0;
        }
        if(a)sum+=arr[a];
        cout << sum << '\n';
    }

}