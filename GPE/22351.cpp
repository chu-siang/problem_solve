#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5] = {0,10,100,1000,10000};
vector<int>v[5];
void solve(){
    for(int i = 0 ;i < 10000; i++){
        int ii = i*i;
        for(int j = 1; j < 5; j++){
            if(i < a[j]){
                int x = (ii/a[j] + ii%a[j]);
                if(x == i)v[j].push_back(ii);
            }
        }
    }
}

signed main(){
    int n;
    solve();
    while(cin >> n){
        n >>= 1;
        for(int i = 0; i < v[n].size(); i++){
            cout <<setw(2*n) <<setfill('0')<< v[n][i] << '\n';
        }
    }
}