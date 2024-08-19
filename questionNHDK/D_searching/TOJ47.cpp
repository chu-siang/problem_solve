#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll>v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        if(binary_search(v.begin(),v.end(),k))
            cout << k << '\n';
        else{
            if(upper_bound(v.begin(),v.end(),k)-v.begin() == 0){
                cout << "no "<< v.begin();
            }else if(upper_bound(v.begin(),v.end(),k)==v.end()){
                cout << v.back() << " no";
            }else{
                cout << *(upper_bound(v.begin(),v.end(),k)-1) << " " <<*upper_bound(v.begin(),v.end(),k);
            }
            cout <<'\n';
        }           
    }
    return 0;
}