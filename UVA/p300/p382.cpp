#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 6e4+5;
signed main(){
    int n;
    cout << "PERFECTION OUTPUT\n";
    while(cin >> n,n){
        int sum = 0;
        for(int i = 1; i < n; i++)if(!(n%i))sum+=i;
        cout  << setw(5) << setfill(' ') << n << "  ";
        if(sum == n)cout << "PERFECT\n";
        else if(sum < n)cout << "DEFICIENT\n";
        else cout << "ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
}