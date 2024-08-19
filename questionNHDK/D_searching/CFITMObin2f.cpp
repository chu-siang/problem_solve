#include<bits/stdc++.h>
using namespace std;
string t,p;
const int MAXN = 2e5+5;
int a[MAXN];

bool check(int mid){
    string s = t;
    for(int i = 0; i < mid; i++){
        s[a[i]-1] = ' '; 
    }
    int len = s.length();
    int cnt = 0;
    int len2 = p.size();
    for(int i = 0; i < len; i++){
        if(s[i] == p[cnt]){
            cnt++;
            if(cnt == len2)return true;
        }
    }
    return false;
}

int main(){
    cin >> t >> p;
    int len1 = t.length();
    for(int i = 0; i < len1; i++)cin >> a[i];
    int l = 0,r = len1;
    while(r - l > 1){
        int mid = l+r >> 1;
        if(check(mid))l = mid;
        else r = mid;
    }
    cout << l << '\n';
}