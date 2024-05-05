#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[10005];

int main(){
    ll l,h,r;
    memset(arr,0,sizeof(arr));
    ll lst = 10005,rst = 0;
    while(cin >> l >> h >> r){
        if(l < lst) lst = l;
        if(r > rst) rst = r;
        for(int i = l; i < r; i++){
            if(h > arr[i]) arr[i] = h;
        }
    }
    ll H = -1;
    for(int i = lst; i <= rst; i++){
        if(arr[i] != H) {
            cout << i << ' ' << arr[i] << " \n"[i==rst];
            H = arr[i];
        }
    }
}