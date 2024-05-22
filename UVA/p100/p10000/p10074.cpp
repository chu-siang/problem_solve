#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
double dp[105][15];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        int mp[105][105];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mp[i][j];
            }
        }
        int mx = 0,tmp,len,wid;
        for(int i = 0; i < n; i++){
            int sum[100]={};
            for(int j = i; j < n; j++){
                for(int k = 0; k < m; k++){
                    sum[k] += !mp[j][k];
                    if(k == 0|| tmp != len*wid){
                        len = 0,tmp = 0;
                    }
                    len++,wid = j-i+1;
                    tmp += sum[k];
                    if(tmp == len*wid) mx = max(mx,tmp);
                }
            }
        }
        cout << mx << '\n';
    }

}