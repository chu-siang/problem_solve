///11321
#include <bits/stdc++.h>

using namespace std;

int n,m,i;
bool cmp(int x, int y){
    if((x % m) != (y % m)){
        return (x % m) < (y % m);
    }
    if((x % 2) * (y % 2)){
        return x > y;
    } 
    if((x % 2 == 0) && (y % 2 == 0)){
        return x < y;
    }       
    return (x%2);   
}

int main(){
    while(cin >> n >> m){
        vector<int> v(n);
        for(i = 0; i < n;) cin >> v[i++];
        cout << n << " " << m << endl;
        if(n == 0){
            break;
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i:v )cout << i << endl;
    }
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 20005;
ll m;
// 若把 a 當前 b 當後  return false 代表交換
bool cmp(ll a,ll b){
    if(a % m == b % m){
        if((a&1) && (b&1)){
            return a > b;
        }else if(!(a&1) && !(b&1)){
            return a < b;
        }else{
            
            //if(b&1) return false;
            //return true;
            
            return (a&1);
        }
    }
    return (a%m) < (b%m);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    while(cin >> n >> m){
        if(n == m && n == 0){
            cout << "0 0\n";
            break;
        }
        vector<ll>v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(),v.end(),cmp);
        cout << n << ' ' << m <<'\n';
        for(auto i : v)cout << i << '\n';
    }
    return 0;
}
*/