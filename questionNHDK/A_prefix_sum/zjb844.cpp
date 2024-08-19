#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    while(cin>>n>>q){
        vector<int> k(n);
        for(int i=0;i<n;i++){
            cin>>k[i];
        }
        sort(k.begin(),k.end());
        for(int i=0,t;i<q;i++){
            cin>>t;
            auto it=upper_bound(k.begin(),k.end(),t);    
            cout<<((it-k.begin())%2?"1\n":"0\n");//it: upperbound 3 6 8 三格數字 
        }
    }
    return 0;
}