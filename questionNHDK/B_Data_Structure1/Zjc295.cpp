#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int sum=0;
    cin>>n>>m;
    vector<int>v,c;
    while(n--){
        int k,max=0;
        for(int i=0;i<m;i++){
            cin>>k;
            if(k>max)max=k;
        }
        sum+=max;
        v.push_back(max);
    }
    cout<<sum<<'\n';
    for(auto i:v){
        if(sum%i==0)
            c.push_back(i);
    }
    if(c.empty())cout<<"-1";
    else{
        int l=c.size();
        for(int i=0;i<l;i++){
            if(i!=l-1)cout<<c[i]<<" ";
            else cout<<c[i];
        }
    }
    return 0;
}