#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN] = {0};
int b[MAXN] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n , car = 0;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--){
            if((a[i] + b[i] + car)/10){
                ans[i] = (a[i] + b[i] + car) %10;
                car = (a[i] + b[i] + car)/10;
            }else {
                ans[i] = (a[i] + b[i] + car) %10;
                car = 0;
            }
        }
        if(car)cout << car;
        for(auto i : ans) cout << i;
        if(t)cout << '\n';
        cout << '\n';
    }
    return 0;
}