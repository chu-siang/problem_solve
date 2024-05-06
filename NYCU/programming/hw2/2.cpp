#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    ll a,b;
    while(t--){
        cin >> a >> b;
        if(a > b) cout << ">\n";
        else if(a < b) cout << "<\n";
        else cout <<"=\n";
    }
}