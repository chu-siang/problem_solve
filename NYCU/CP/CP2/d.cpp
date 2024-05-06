//Bungee Builder
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int a[MAXN];

int hight(vector<int>v){
    stack<int>H;
    int l;
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        int h = v[i];
        if(H.empty()){
            H.push(h);
            l = h;
            continue;
        }
        if(h >= l){
            int d1 = l;
            while(H.size() > 0){
                int d2 = H.top();
                ans = max(ans,d1-d2);
                H.pop();
            }
            l = h;
            H.push(h);
        }else{
            H.push(h);
        }
    }
    return ans;
}

signed main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++)cin >> v[i];
    int a = hight(v);
    reverse(v.begin(),v.end());
    int b = hight(v);
    cout << max(a,b) << '\n';
}