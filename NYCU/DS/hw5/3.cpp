//uva532
#include<bits/stdc++.h>
using namespace std;
int k;
int arr[15];
vector<int>v;
void dfs(int n,int a){
    if(n == 6){
        for(int i = 0; i < 6; i++){
            cout << v[i] << " \n"[i==5];
        }
        
        return;
    }
    for(int i = a; i < k; i++){
        v.push_back(arr[i]);
        dfs(n+1,i+1);
        v.pop_back();
    }
}

signed main(){
    cin >> k;
    for(int i = 0; i < k; i++)cin >> arr[i];
    dfs(0,0);
}