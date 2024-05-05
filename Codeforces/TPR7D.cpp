#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int  k = 1; k <= 6; k++){
                if(i + j + k == n) ans++;
            }
        }
    }
    cout << ans << '\n';
}