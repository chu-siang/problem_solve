#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        int b;
        cin >> a >> b;
        for(int k = 0; k < b; k++){
            if(a > 9)a = 9;
            for(int i = 1; i <= a; i++){
                for(int j = 1; j <= i; j++)cout << i;
                cout << '\n';
            }
            for(int i = a-1; i >= 1; i--){
                for(int j = i; j >= 1; j--)cout << i;
                cout << '\n';
            }
            if(t||k!=b-1)cout << '\n';
        }
    }
}