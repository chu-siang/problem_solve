#include<iostream>
using namespace std;

int main(){
    long long n;
    int t;
    cin >> t;
    while(t--){
        long long a,b;
        cin >> a >> b;
        if(a > b) cout << '>';
        else if(a < b)  cout << '<';
        else cout << "=";
        cout << '\n';
    }
}