#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;

ll e = 1;

struct Nd{
    int num,d = 0,sum,mentor = 0;
}nd[MAXN];

bool cmp_1(Nd a,Nd b){
    return a.sum < b.sum;
}

bool cmp_2(Nd a,Nd b){
    return a.num < b.num;
}

int main(){
    ll n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> nd[i].sum;
        nd[i].num = i;
    }
    int x,y;
    for(int i = 0; i < k; i++){
        cin >> x >> y;
        if(nd[x].sum > nd[y].sum) nd[x].d++;
        else if(nd[x].sum < nd[y].sum)nd[y].d++;
        
    }
    sort(nd+1,nd+n+1,cmp_1);
    for(int i = 2; i <= n; i++){
        if(nd[i].sum == nd[i-1].sum){
            nd[i].mentor =  nd[i-1].mentor;
            e++;
        }else nd[i].mentor = nd[i-1].mentor+e,e=1;
    }
    sort(nd+1,nd+n+1,cmp_2);
    for(int i = 1; i <= n; i++){
        cout << nd[i].mentor - nd[i].d << ' ';
    }
}