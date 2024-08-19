#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5+5;
int n,k;
int board[MAXN],poster[MAXN];

bool check(int height){
    int cnt = 0,success = 0;
    int idx = 0;
    for(auto w : board){
        if(w >= height)cnt++;
        else cnt = 0;
        if(idx == k)break;
        if(poster[idx] == cnt){
            success++;
            cnt = 0;
            idx++;
        }
    }
    return success==k;
}


int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    for(int i = 0; i < k; i++)
        cin >> poster[i];
    int l = 1, r = *max_element(board,board+n)+1;
    while(r - l > 1){
        int mid = (l+r)>>1;
        if(check(mid))l = mid;
        else r = mid;
    }
    cout << l << '\n';
}