#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

char c[105][105];
bool mp[105][105] ={0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n, m;
    int i = 0;
    while(cin >> n >> m,n){
        if(i)cout << '\n';
        i++;
        cout << "Field #" << i << ":\n";
        bool mp[105][105] ={0};
        for(int i = 0; i < 105; i++){
            for(int j = 0; j < 105; j++){
                c[i][j] = '.';
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> c[i][j];
                if(c[i][j] == '*')mp[i][j] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(c[i][j] == '.'){
                    int t = 0;
                    t = (mp[i-1][j-1] + mp[i-1][j] + mp[i-1][j+1]
                        + mp[i][j-1] + mp[i][j] + mp[i][j+1]
                        + mp[i+1][j-1] + mp[i+1][j] + mp[i+1][j+1]
                    );
                    c[i][j] = '0'+t;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << c[i][j];
            }
            cout << '\n';
        }
    }
}
