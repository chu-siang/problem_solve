#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 505;
int X[maxn], Y[maxn], Z[maxn];
 
int main() {
    string s1, s2;
    while (cin >> s1 >> s2){
        if (s1 == "0" || s2 == "0"){
            cout << "0\n";
            continue;
        }
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(Z, 0, sizeof(Z));
        if (s1.size() < s2.size()) swap(s1, s2);
        int n1 = (int)s1.size();
        int n2 = (int)s2.size();
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < n1; i++){
            X[i] = s1[i] - '0';
        }
        for (int i = 0; i < n2; i++){
            Y[i] = s2[i] - '0';
        }
        int carry = 0;
        for (int i = 0; i < n2; i++){
            if (Y[i] == 0) continue;
            for (int j = 0; j < n1; j++){
                int tmp = X[j] * Y[i] + carry + Z[j+i];
                Z[j+i] = tmp % 10;
                carry = tmp / 10;
            }
            int pos = n1 + i;
            while (carry){
                int tmp = Z[pos] + carry;
                Z[pos++] = tmp % 10;
                carry = tmp / 10;
            }
        }
        bool zero = true;
        for (int i = maxn-1; i >= 0; i--){
            if (zero && Z[i] == 0) continue;
            else {
                zero = false;
                cout << Z[i];
            }
        }
        cout << "\n";
    }
    return 0;
}

/*
python
import sys
counter = 1
last = 0
for line in sys.stdin:
    num = int(line)
    if counter % 2 == 0:
        print(num * last)
    last = num
    counter += 1
*/