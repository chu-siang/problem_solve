#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int,string>a,pair<int,string>b){
    return a.first > b.first;
}

int main(){
    int t;
    cin >> t;
    pair<int,string>p[10];
    for(int c = 1; c <= t; c++){
        int num,mx = 0;
        string s;
        for(int i = 0; i < 10; i++){
            cin >> s >> num;
            if(num > mx) mx = num;
            p[i] = {num,s};
        }
        sort(p,p+10,cmp);
        cout << "Case #" << c << ":\n";
        for(int i = 0; i < 10; i++){
            if(p[i].first == mx) cout << p[i].second << '\n';
        }
    }
}
