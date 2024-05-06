//a101(oj)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int a[105];
        memset(a,0,sizeof(a));
        ll avg;
        ll sum = 0;
        for(int i = 0; i < n; i++) cin >> a[i],sum+=a[i];
        avg = sum/n;
        sort(a,a+n);
        cout << 2*(abs(a[n-1] - a[0]))<< '\n';
    }
}