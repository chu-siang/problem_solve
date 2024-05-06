#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    
    while(cin >> n){
        int count = 0;
        int empty = 0;
        while(n){
            count += n;
            empty += (n%3);
            n/=3;
        }
        while(empty){
            count += (empty/3);
            if(empty == 1){
                empty = 0;
            }else if(empty == 2){
                count++;
                empty = 0;
            }else {
                empty = (empty%3) + empty/3;
            }
        }
        cout << count << '\n';
    }
}