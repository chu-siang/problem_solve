#include<iostream>
#include<cmath>
#define ll long long
#define ccb ios_base::sync_with_stdio(0),cin.tie(0) 
using namespace std;

ll a[2501][2501]={0};

int main(){
    ccb;
    ll n;
    ll m;
    ll c1;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>c1;
            a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+c1;
        }
    }
    ll q;
    cin>>q;
    ll x1,x2,y1,y2;
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        x1++,y1++,x2++,y2++;
        cout<<a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1]<<'\n';
    }
}
//-std=c++17