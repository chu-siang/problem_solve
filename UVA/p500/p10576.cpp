#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s,d;
ll mx = -1e13;
ll months[13] = {0};

bool f(int n){
    if(n < 5)return false;
    ll sum = 0;
    for(int i = n-1; i >= n-5; i--){
        sum += months[i];
    }
    if(sum < 0) return false;
    else return true;
}
void dfs(ll day,ll sur){
    if(day > 5 && f(day))return;
    if(day > 12){
        mx = max(mx,sur);
        return;
    }
    if(day > 5 && f(day))return;
    months[day] = s;
    dfs(day+1,sur+s);
    months[day] = -d;
    dfs(day+1,sur-d);
}

int main(){
    while(cin >> s >> d){
        mx = -1e13;
        memset(months,0,sizeof(months));
        dfs(1,0);
        if(mx < 0) cout << "Deficit\n";
        else cout << mx << '\n';
    }
    return 0;
}