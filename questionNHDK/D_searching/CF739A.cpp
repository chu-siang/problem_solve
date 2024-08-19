#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int arr[MAXN];

int main(){
    int c = 0;
    for(int i = 1; i <= 1e5+5;i++){
        if(i%3 != 0 ) arr[c++] = i;
    }
    int t,n;
    cin>>t;
    while(t--){
        cin >> n;
        cout << arr[n] << '\n';
    }
    return 0;
}