#include <iostream>
#include <cmath>
using namespace std;
  
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    while (cin >> a >> b && a + b){
        int n1 = sqrt(a);
        int n2 = sqrt(b);
        if (n1*n1 != a) n1++;
        cout << n2 - n1 + 1 << "\n";
    }
    return 0;
}