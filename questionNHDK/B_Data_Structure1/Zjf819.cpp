#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define all(a) (a).begin(), (a).end()
#define int  long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>s;
    int  a,b;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(b>100){
            s.push_back(a);
            sum+=(b-100)*5;
        }
    }
    sort(all(s));
    if(s.empty())cout<<'0';
    else{
        for(auto k:s)cout<<k<<' ';
        cout<<'\n'<<sum;
    }
}