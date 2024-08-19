#include<bits/stdc++.h>
#define ll long long 
using namespace std;


int solve(int a, int b, int c){
    int sum = 0;
    int even = 0, odd = 0;
    (a&2) ? odd++ : even++;
    (b&2) ? odd++ : even++;
    (c&2) ? odd++ : even++;
    if(odd == 2) sum++;
    if(even == 2) sum += 2;
    if(odd == 0 || even == 0) sum+=5;
    if(a&1 == b&1) sum +=5;
    if(b&1 == c&1) sum +=5;
    if(a + c > b) sum+=5;
    int total = a + b + c;
    total -= max(max(a,b),c);
    if(total > max(max(a,b),c))sum+=7;
    
    return sum;
}
int main(){
    int mx = -1e9;
    vector<int>v(3);
    cin >> v[0] >> v[1] >> v[2];
    mx = solve(v[0],v[1],v[2]);
    while(next_permutation(v.begin(),v.end())){
        mx = max(mx,solve(v[0],v[1],v[2]));
    }
    cout << mx <<'\n';
    /*
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int mx = -1e9;
    int v[3];
    cin >> v[0] >> v[1] >> v[2];
    mx = solve(v[0],v[1],v[2]);
    while(next_permutation(v,v+3)){
        mx = max(mx,solve(v[0],v[1],v[2]));
    }
    cout << mx <<'\n';
    */
}