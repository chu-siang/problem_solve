//uva 10137
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[1005];

signed main(){
    int n;
    bool flag = false;
    while(cin >> n,n){
        double num;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> num;
            a[i] = (int)(round(num*100.0));
            sum += a[i];
        }
        int avg = sum/n;
        int dis = sum%n;
        double ans = 0;
        sort(a,a+n);
        for(int i = n-1; i >= 0; i--){
            if(dis){
                ans += abs(a[i]-(avg+1));
                dis--;
            }else{
                ans += abs(a[i]-avg);
            }
        }
        ans/=200.0;
        cout << "$"<< fixed  << setprecision(2) << ans << '\n';
    }   
}