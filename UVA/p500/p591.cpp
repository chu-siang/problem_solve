#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e5+5;
int a[MAXN];

signed main(){
    int n,k;
    int c = 0;
    bool flag = false;
    while(cin >> n,n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum +=a[i];
        }
        k = sum / n;
        sort(a,a+n);
        int dis = 0;
        for(int i = 0; a[i] <= k && i < n; i++){
            dis += abs(k - a[i]);
        }
        cout << "Set #" << ++c << "\n";
        cout << "The minimum number of moves is " << dis << ".\n\n";
    }
}