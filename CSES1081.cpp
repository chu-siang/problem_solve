#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> v(1e6+1,0);
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        v[a]++;
    }
    for(int gcd = 1e6; gcd >= 1; gcd--){
        int multiples = 0;
        for(int pointer = gcd; pointer <= 1e6; pointer+=gcd){
            multiples += v[pointer];
        }
        if(multiples > 1) {
            cout << gcd;
            return 0;
        }
    }
    return 0;
}