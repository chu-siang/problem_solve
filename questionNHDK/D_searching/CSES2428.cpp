#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    int j = 0;
    map<int,int> occurences;
    for(int i = 0; i < n; i++){
        while(j < n && ((int)occurences.size() < k || occurences.count(v[j]) > 0)){
            occurences[v[j]]++;
            j++;
        }
        ans += (j-i);
        occurences[v[i]]--;
        if(occurences[v[i]] == 0)
            occurences.erase(v[i]);
    }
    cout << ans;
}