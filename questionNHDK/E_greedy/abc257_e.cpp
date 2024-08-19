#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =1e6+5;
int a[MAXN],b[MAXN];
signed main(){
    int n;
    cin >> n;
    for(int i = 1; i <= 9; i++)cin >> a[i];
    int mi = *min_element(a+1,a+10);
    int len = n/mi;
    for(int i = 1; i <= len; i++){
        for(int j = 9; j >= 1; j--){
            if(mi*(len-i) + a[j] <= n){
                n-=a[j];
                cout << j;
                break;
            }
        }
    }
}