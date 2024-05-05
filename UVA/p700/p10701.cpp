//uva 10701
#include<bits/stdc++.h>
using namespace std;

string a,b;
int idx = 0;
void travel(int l,int r){
    if(l > r)return;
    int i;
    for(i = l; i <= r; i++){
        if(a[idx] == b[i])break;
    }
    if(i != r+1){
        idx++;
        travel(l,i-1);//left
        travel(i+1,r);//right
        cout << b[i];//root;
    }
}

signed main(){
    while(cin >> a >> b){
        int l = a.length();
        travel(0,l-1);
        cout << '\n';
    }
}