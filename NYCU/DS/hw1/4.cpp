#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int MAXN = 3e5+5;
int a[105][105];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    char c;
    cin >> n;
    //(n+1)/2
    int cnt = 0;
    for(int i = 0; i < (n+1)/2; i++){
        for(int j = 0; j < n-i; j++){
            if(!a[i][j])a[i][j] = ++cnt;
        }
        for(int j = 0; j < n-i; j++){
            if(!a[j][n-1-i])a[j][n-1-i] = ++cnt;
        }
        for(int j = 0; j < n-i; j++){
            if(!a[n-1-i][n-j-i-1])a[n-1-i][n-j-i-1] = ++cnt;
        }
        for(int j = 0; j < n-i; j++){
            if(!a[n-1-j-i][i])a[n-1-j-i][i] = ++cnt;
        }
    }
    cnt = 0;
    cout << '[';
    for(int i = 0; i < n; i++){
        cout << '[';
        for(int j = 0; j < n; j++){
            if(j!=0)cout << ',';
            cout << a[i][j];
        }
        cout << ']';
        cout << ",]"[i==n-1];
    }
    cout << '\n';

}
