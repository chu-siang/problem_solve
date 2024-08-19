#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> mp;
        for(int i = 1; i <= n; i++){
            int x;
            cin >>x;
            mp[x] = i;
        }
        ll ans = 0;
        for(auto &[a,i] : mp){
            for(int b = 1; a * b <= 2 * n -1; b++){
                if(a == b) continue;
                if(mp.count(b) && mp[b] + i == a * b) ans++ ;
            }
        }
        cout << ans/2 << '\n';
    }
}

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5+5;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ll t, n,a;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<ll,ll>>v(n);
        for(int i = 0; i < n; i++){
            cin >> a;
            v[i].first = a;
            v[i].second = i+1;
        }
        sort(v.begin(),v.end());
        ll cnt = 0;
        for(int i = 0; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(v[i].first * v[j].first > 2 * n)break;
                if(v[i].first * v[j].first == v[i].second + v[j].second)cnt++;
            }
        }
        cout << cnt << '\n';
    }
}*/