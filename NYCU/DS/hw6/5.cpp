#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4;
int  a[MAXN];
signed main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n-i; j++){
            if(a[j-1] > a[j]){
                swap(a[j-1],a[j]);
                cnt++;
            }
        }
    }
    cout << cnt <<'\n';
}