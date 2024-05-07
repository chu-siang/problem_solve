#include <iostream>
using namespace std;
 
int main() {
    int n;
    while (cin >> n){
        int num = 1;
        int cnt = 1;
        while (num % n != 0){
            num %= n;
            num *= 10;
            num += 1;
            cnt++;
        }
        cout << cnt << "\n";
    }
}