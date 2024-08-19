#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e5+5;
pair<int,int>p[MAXN];




signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int>ans;
    ans.push_back(1);
    int ptr = 1;
    while(ptr < n){
        for(auto &i : ans)i <<= 1;
        for(int i = 0; i < ptr; i++)ans.push_back(ans[i]-1);
        ptr <<= 1;
    }
    for(auto i : ans){
        if(i <= n)cout << i << ' ';
    }
    cout << '\n';
}