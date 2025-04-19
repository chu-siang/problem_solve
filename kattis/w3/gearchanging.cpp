#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+5;
int a[MAXN];

signed main(){
    int n, m;
    double p;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    vector<int>f(n);
    vector<int>b(m);
    for(int i = 0; i < n; ++i){
        cin >> f[i];
    }   
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
    vector<double>r;
    for(auto i : f){
        for(auto j : b){
            r.emplace_back((double)i/(double)j);
        }
    }
    sort(r.begin(), r.end());
    for(size_t i = 1; i < r.size(); ++i){
        if(r[i-1] + r[i-1] * p / 100.0 < r[i]){
            cout << "Time to change gears!\n";
            return 0;
        }
    }
    cout << "Ride on!\n";
}