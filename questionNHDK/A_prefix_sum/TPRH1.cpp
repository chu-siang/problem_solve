#include<iostream>
#include<cmath>
#define ll long long
#define c ios_base::sync_with_stdio(0),cin.tie(0) 
using namespace std;

ll a[2501][2501];
int main(){
    c;
    int n;
    int m;
    int t;
    cin>>n;
    a[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>t;
        a[i]=a[i-1]+t;
    }
    ll n1;
    cin>>n1;
    ll l,r;
    while(n1--){
        cin>>l>>r;
        cout<<abs(a[r]-a[l-1])<<endl;
    }
}
//-std=c++17