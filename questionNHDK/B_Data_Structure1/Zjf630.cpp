#include<iostream>
#include<bitset>
#define MAXN 2505
using namespace std;

bitset<MAXN> Friend [MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1, d; i <= n; i++){
        cin >> d;
        for(int j = 0, f; j < d; j++){
            cin >> f;
            Friend[i][f] = true;
        }
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            ans += (Friend[i] & Friend[j]).any();
        }
    }
    cout << ans << '\n';
}