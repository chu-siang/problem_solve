#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a, b;
    cin >> a >> b;
    int ansi = 0, ansj = 0, ans = 0;
    long long mini = 2LL << 20;
    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= 10; j++){
            int tmp = (a*i + b*j);
            if(mini >= (n - tmp) && (n-tmp) >= k){
                if(i >= ansi){
                    ansi = i;
                    ansj = j;
                    ans = n - tmp;
                    mini = ans;
                }
            }
        }
    }
    cout << ansi << " " << ansj << " " << mini - k << '\n';
}