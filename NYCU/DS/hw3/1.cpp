#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5;
int a[MAXN];
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = i+1; j < n; j++){
            if(a[j] > a[i]){
                cout << j-i << " "[i==n-1];
                flag = false;
                break;
            }
        }
        if(flag || (i == n-1))cout << 0 << " \n"[i==n-1];
    }
}