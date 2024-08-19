#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    int n,m,k;
    while(q--){
        cin >> n >> m >> k;
        int l = 0 , r = k;
        while(l < r){
            int mid = (l + r)/2;
            if(n + mid > m){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << k-l+1 << endl;
    }
}