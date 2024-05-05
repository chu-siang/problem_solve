//uva 10140
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;

vector<int>v;
bool visit[MAXN];
bool mp[1000005];
signed main(){
    for(int i = 2; i <=1e5; i++){
        if(!visit[i]){
            v.push_back(i);
        }
        for(auto j :v){
            if(j*i>=1e5)break;
            visit[j*i]=1;
            if((i%j) == 0)break;
        }
    }
    int a,b;
    int llf = 1e9;
    while(cin >> a >> b){
        memset(mp,0,b-a+1);
        for(int i = 2; i <= sqrt(b); i++){
            if(visit[i])continue;
            for(int j = max(2LL,(a+i-1)/i)*i; j <= b; j+=i){
                mp[j-a]=1;
            }
        }
        int pre = 0;
        int t1 = llf, t2 = -llf;
        int a1,a2,b1,b2;
        for(int i = a; i <= b; i++){
            if(!mp[i-a] && i > 1){
                if(pre){
                    if(i - pre < t1){
                        t1 = i - pre;
                        a1 = pre, a2 = i;
                    }
                    if(i - pre > t2){
                        t2 = i - pre;
                        b1 = pre, b2 = i;
                    }
                }
                pre = i;
            }
        }
        if(t1 == llf||t2 == llf)cout << "There are no adjacent primes.\n";
        else cout << a1 << ',' << a2 << " are closest, "<< b1 <<','<< b2<<" are most distant.\n";
    }
}