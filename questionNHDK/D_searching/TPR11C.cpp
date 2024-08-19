#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int arr[MAXN] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= 100; k++){
                arr[i+j+k]++;
                arr[i*j*k]++;
                arr[i*j+k]++;
                arr[i+j*k]++;
            }
        }
    }
    int q,n;
    cin >> q;
    while(q--){
        cin >> n;
        cout << arr[n] <<'\n';
    }
    return 0;
}