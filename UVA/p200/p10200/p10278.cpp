#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;
    cin >> t;
    bool flag = false;
    while(t--){
        int f;
        vector<int>firenum;
        cin >> f;
        int n;
        cin >> n;
        for(int i = 0; i < f;i++){
            int tmp;
            cin >> tmp;
            firenum.push_back(tmp);
        }
        int a,b,l;
        vector<vector<int>>G(n+2,vector<int>(n+2,1e9));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                G[i][j] = G[j][i] = 1e9;
            }
        }
        string s;
        stringstream ss;
        cin.ignore();
        while(getline(cin,s)){
            if(s == "\n" || s == "")break;
            ss << s;
            ss >> a >> b >> l;
            G[a][b] = G[b][a] = l;
            ss.clear();
            ss.str("");
        }

        for(int i = 1; i <= n; i++)G[i][i] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= n; k++){
                    int through = G[j][i] + G[i][k];
                    if(G[j][k] > through){
                        G[j][k] = through;
                    }
                }
            }
        }
        vector<int>shortest(n+2,1e9);
        int mxlength = 0;
        for(int i = 1; i <= n; i++){
            int dis = 1e9;
            for(int j = 0; j < f; j++){
                int through = G[i][firenum[j]];
                if(through < dis){
                    dis = through;
                }
            }
            shortest[i] = dis;
            if(dis > mxlength)mxlength = dis;
        }
        int ans = 1;
        for(int i = n; i >= 1; i--){
            int tmpl = 0;
            for(int j = 1; j <= n; j++){
                if(G[j][i] < shortest[j]){
                    if(tmpl < G[j][i]){
                        tmpl = G[j][i];
                    }
                }else{
                    if(tmpl < shortest[j]){
                        tmpl = shortest[j];
                    }
                }
            }
            if(tmpl <= mxlength){
                ans = i;
                mxlength = tmpl;
            }
        }
        if(flag)cout << '\n';
        flag = true;
        cout << ans << '\n';
    }
}