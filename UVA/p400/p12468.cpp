//uva 12468
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        //if(n == m && n == -1) break;
        if(n > m)swap(n,m); // 交換目的是要讓大減小固定
        cout << min(m - n,100 - m + n) << '\n';//往上找 跟往下找 找最小 一個圓環的感覺
    }
}