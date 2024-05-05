#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int sum = 0;
        int empty = 0;
        while(n !=  0){
            sum += n;
            empty += (n%3);
            n/=3;
        }
        while(empty != 0){
            sum += (empty/3);
            if(empty <= 1){
                empty = 0;
            }else if(empty == 2){
                sum ++;
                empty = 0;
            }else{
                empty = (empty/3) + (empty%3);
            }
        }
        cout << sum << '\n';
    }
}