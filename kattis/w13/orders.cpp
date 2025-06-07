#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e3+5;
const int MAX_M = 3e4+1;
int arr[MAXN];


signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)cin >> arr[i];
    int m,s;

    vector<int> dp(MAX_M, 0);
    auto mx = *max_element(arr, arr + n);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
	    for(int	j = arr[i]; j <= mx; ++j){
            dp[j] += dp[j-arr[i]];
        }
    }
    cin >> m;
    while(m--){
        cin >> s;
        if(dp[s] == 0){
            cout << "Impossible\n";
        } else if (dp[s] > 1) {
            cout << "Ambiguous\n";
        } else {
            vector<int> ans;
            int current = s;
            for(int i = n - 1; i >= 0 && current > 0; --i){
                while(current >= arr[i] && (dp[current - arr[i]] == 1)){
                    ans.push_back(i + 1);
                    current -= arr[i];
                }

            }
            for(int i = ans.size() - 1; i >= 0; --i){
                cout << ans[i] << (i == 0 ? '\n' : ' ');
            }
        }
    }
}