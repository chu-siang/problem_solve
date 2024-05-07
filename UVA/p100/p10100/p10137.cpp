#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1005];

int main(){
    ll n;
    while(cin >> n,n){
        double num;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin >> num;
            a[i] = (ll)round(num*100.0);

            sum += a[i];
        }
        sort(a,a+n);
        ll avg = sum/n;
        ll dis = sum%n;
        double ans = 0;
        // 多減掉剩下的是因為共產主義 把錢錢分不掉的去掉 因為是尾數剩一點點所以被除掉的時候沒差
        for(int i = n - 1; i >= 0; i--){
            if(dis){
                ans += abs(a[i] - (avg + 1));
                dis--;
            }
            else ans += abs(a[i]-avg);
        }
        ans /= 200.0;
        cout <<'$'<< fixed << setprecision(2) << ans << '\n';
    
    }

}
