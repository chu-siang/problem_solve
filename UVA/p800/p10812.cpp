#include<iostream>
using namespace std;

int main(){
    int n, m;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(m > n || ((m + n)&1)){
            cout << "impossible" << '\n';
            continue;;
        }
        int bi =  (m + n) / 2;
        int sm = m - bi;
        cout << bi << " "<< sm << '\n';
    }
}