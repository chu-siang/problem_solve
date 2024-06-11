//uva11059
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[20];
signed main(){
    int n;
    int CASE = 0;
    while(cin >> n){
        for(int i = 0; i < n; i++)cin >> a[i];
        cout  << "Case #" << ++CASE << ": ";
        int ans = -1e9;
        
        for(int i = 0; i < n; i++){
            ans = max(ans,a[i]);
            int tmp = 1;
            for(int j = i; j < n; j++){
                tmp*=a[j];
                ans = max(tmp,ans);
            }
        }
        if(ans < 0)ans = 0;
        cout <<"The maximum product is "<< ans << ".\n\n";
    }
}