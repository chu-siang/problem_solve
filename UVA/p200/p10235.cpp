#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(int n){
    if(n <= 2) return true;
    for(int i = 2; i * i <= n; i++){
        if(n%i == 0)return false;
    }
    return true;
}

int main(){
    int n;
    while(cin >> n){
        if(!isPrime(n)){
            cout << n << " is not prime.";
        }else{
            int num = 0;
            int tmp = n;
            while(n){
                num*=10;
                num += n % 10;
                n/=10;
            }
            if(num != tmp){
                if(isPrime(num)){
                    cout << tmp << " is emirp.";
                }else cout << tmp << " is prime.";
            }else cout << tmp << " is prime.";
        }
        cout << '\n';
    }
    return 0;
}