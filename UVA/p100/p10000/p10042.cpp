#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>prime;
const int MAXN = 1e5+5;
bool visit[MAXN];
int isnum(int n){
    int sum = 0;
    while(n){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}

int issm(int n){
    int sum = 0;
    for(auto i:prime){
        if(i*i > n)break;
        while(n%i == 0){
            sum+=isnum(i);
            n/=i;
        }
    }
    if(sum == 0)sum = -1;
    else if(n > 1){
        sum+=isnum(n);
    }
    return sum;
}
signed main(){
    memset(visit,0,sizeof(visit));
    for(int i = 2; i <= 1e5; i++){
        if(!visit[i]){
            prime.push_back(i);
        }
        for(auto t:prime){
            if(i*t > 1e5)break;
            visit[i*t] = 1; 
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = n+1;; i++){
            if(issm(i) == isnum(i)){
                cout << i;
                break;
            }
        }
        cout << '\n';
    }
}