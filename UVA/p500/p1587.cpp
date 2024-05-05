#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    pair<int,int>a[6];
    while(cin >> a[0].first){
        cin >> a[0].second;
        if(a[0].first > a[0].second)swap(a[0].first,a[0].second);
        for(int i = 1; i < 6; i++){
            cin >> a[i].first >> a[i].second;
            if(a[i].first > a[i].second)swap(a[i].first,a[i].second);
        }
        sort(a,a+6,cmp);
        bool flag = false;
        for(int i = 0; i < 6; i+=2){
            if(a[i].first != a[i+1].first || a[i].second != a[i+1].second)flag = true;
        }
        if(a[0].first != a[2].first || a[0].second != a[4].first||a[2].second != a[4].second)flag = 1;
        if(flag) cout << "IMPOSSIBLE\n";
        else cout << "POSSIBLE\n";
    }
}