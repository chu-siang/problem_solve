#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int c = 0;
    int n, x,value;
    cin >> n >> x;
    map<int,int>mp;
    for(int i = 1; i <= n; i++){
        cin >> value;
        if(mp.count(x-value)){
            cout << mp[x-value] << " " << i<<endl;
            return 0;
        }
        mp[value] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,x,num;
    cin >> n >> x;
    vector<pair<ll,ll>>v;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.emplace_back(make_pair(num,i+1));
    }
    sort(v.begin(),v.end());
    bool flag = false;
    for(int i = 0 , j = n - 1; i < j;){
        if(v[i].first + v[j].first == x){
            cout << v[i].second << ' ' << v[j].second;
            flag = true;
            break;
        }else if(v[i].first + v[j].first < x)i++;
        else j--;
    }
    if(!flag) cout << "IMPOSSIBLE";
}
*/