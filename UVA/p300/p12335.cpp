#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    int f[22];
    f[0] = 1;
    for(int i = 1; i < 22; i++){
        f[i] = i*f[i-1];
    }
    int vis[22] ={0};
    char ans[25];
    for(int cs = 1; cs <= t; cs++){
        string s;
        int k;
        cin >> s >> k;
        cin.ignore();
        int l = s.length();
        k--;
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < l; i++){
            int pos = k/f[l-i-1];
            k-=pos*f[l-i-1];
            for(int j = 0; j < pos || vis[j] == 1; j++){
                if(vis[j]!=0)pos++;
            }
            ans[pos] = s[i];
            vis[pos] = 1;
        }
        ans[l] = '\0';
        cout << "Case " << cs << ": " << ans << '\n';
    }
}