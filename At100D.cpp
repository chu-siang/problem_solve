#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int MAXN = 100005;

struct Node{
    ll a, b, c;
}p[MAXN];
int i, j, k;
bool cmp(Node x, Node y){
    return x.a*i + x.b*j + x.c*k > y.a*i + y.b*j + y.c*k;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    ll ans = 0;
    for(i = -1; i <= 1; i+=2){
        for(j = -1; j <= 1; j+=2){
            for(k = -1; k <= 1; k+=2){
                sort(p+1,p+1+n,cmp);
                ll t[4]={0};
                for(int me = 1; me <= m; me++){
                    t[1]+=p[me].a,t[2]+=p[me].b,t[3]+=p[me].c;
                }
                ans = max(ans,t[1]*i+t[2]*j+t[3]*k);
            }
        }
    }
    cout << ans;
}