#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int ans[maxn];
int main(){
    int t,n,a,b;
    cin>>t>>a>>b;
    while(t--){
        cin>>n>>a>>b;
        if(abs(a-b)>1 || (a+b)>(n-2)){
            cout<<"-1"<<endl;
            continue;
        }
        int l=1,r=n,flag=(a>b)?1:0;
        for(int i=1;i<=n;++i){
            if(flag)
                ans[i]=l++;
            else 
                ans[i]=r--;
            
        }


    }
    return 0;
}