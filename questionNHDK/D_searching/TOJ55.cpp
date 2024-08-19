#include<bits/stdc++.h>
using namespace std;

int main(){
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
        cout << upper_bound(v.begin(),v.end(),num)-lower_bound(v.begin(),v.end(),num);
        cout << '\n';
    }
    return 0;
}