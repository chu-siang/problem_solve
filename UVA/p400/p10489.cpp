#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n, b;
        cin >> n >> b;
        vector<int> v(n+1,0);
        long long k;
        cin >> k;
        int sum = 1;
        for(int i = 1; i <= k; i++) cin >> v[i];
        for(int i = 1; i <= k; i++){
            sum = (sum*v[i]);
            sum %= n;
        }
        cout << sum << endl;
    }
}