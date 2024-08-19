#include<iostream>
#include<bitset>
using namespace std;

int main(){
    bitset<100001>bt;
    int n, m;
    cin >> n >> m;
    bt[0] = 1;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        bt = (bt << a) | (bt << b);
    }
    cout << (bt[m] ? "Yes" : "No" );
}