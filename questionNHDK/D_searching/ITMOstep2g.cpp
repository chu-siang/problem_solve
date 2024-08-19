#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxm = 3e5+5;
struct STK{
    vector<int>s,val = {0};
    void push(int x){
        s.push_back(x);
        val.push_back(__gcd(val.back(),x));
    }
    int top(){
        return s.back();
    }
    int gcd(){
        return val.back();
    }
    void pop(){
        s.pop_back();
        val.pop_back();
    }
    bool empty(){
        return s.empty();
    }
}s1,s2;

int a[maxm];
int n;
void add(int x){
    s2.push(x);
}
void del(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    s1.pop();
}
bool good(){
    int g1 = s1.gcd();
    int g2 = s2.gcd();
    return __gcd(g1,g2)==1;
}
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    int l = 1;
    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        add(a[i]);
        while(good()){
            ans = min(ans,i-l+1);
            del();
            l++;
        }
    }
    if(ans == 1e9)ans=-1;
    cout << ans << '\n';
}