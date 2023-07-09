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
    if(a&2 == b&2) sum +=5;
    if(b&2 == c&2) sum +=5;
    if(a + c > b) sum+=5;
    int total = a + b + c;
    total -= max(max(a,b),c);
    if(total > max(max(a,b),c))sum+=7;
    
    return sum;
}
int main(){
    int a[3],mx = -1e9;
    cin >> a;
    mx = solve(a[0],a[1],a[2]);
    mx = max(mx,solve(next_permutation(a,a+3)));
    cout << mx <<'\n';
}