//uva 10038
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    while(cin >> n){
        bool a[3000] = {false};
        ll tmp,now;
        cin >> tmp;
        bool flag = false;
        for(int i = 1; i < n; i++){
            cin >> now;
            if(a[abs(now-tmp)])flag = true;
            else if(abs(now-tmp) >= n || now == tmp)flag = true;
            a[abs(now-tmp)] = 1;
            tmp = now;
        }
        if(flag)cout << "Not jolly\n";
        else cout <<"Jolly\n";
    }
}