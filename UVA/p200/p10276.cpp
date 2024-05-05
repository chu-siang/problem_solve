#include<bits/stdc++.h>
#define int long long
using namespace std;

int pegs[55];

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int peg = 1;
        for(int i = 1; i <= n; i++){
            pegs[i] = 0;
        }
        for(int i = 1; ; i++){
            bool flags = false;
            for(int j = 1; j <= peg; j++){
                int tmp = i + pegs[j];
                int v = sqrt(tmp);
                if(v*v == tmp){
                    pegs[j] = i;
                    flags = true;
                    break;
                }
            }
            if(!flags){
                peg++;
                pegs[peg] = i;
                if(peg > n){
                    cout << i-1<< '\n';
                    break;
                }
            }
        }
    }
}