#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+5;
int arr[MAXN] = {0};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr[num]++;
    }
    for(int i = 1e6; i >= 1; i--){
        int cnt = 0;
        for(int j = i; j <= 1e6; j+=i){
            cnt += arr[j];
        }
        if(cnt > 1){
            cout << i;
            break;
        }
    }
}
    