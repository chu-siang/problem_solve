#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;
        cout << upper_bound(v.begin(),v.end(),num)-lower_bound(v.begin(),v.end(),num)<<'\n';
    }
    return 0;
}