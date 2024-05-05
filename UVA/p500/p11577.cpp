#include <iostream>
#include <map>
using namespace std;
   
int main() {
    int T;
    cin >> T;
    string s;
    getline(cin, s); //混用cin與getline，先清除cin之後的緩衝區
    while (T--) {
        getline(cin, s);
        int a[26] = {}; //大小寫字母不分
        int mx = 0;
        for (int i = 0; i < s.size(); i++) {
            int idx = -1;
            if (s[i] >= 'A' and s[i] <= 'Z') {
                idx = s[i] - 'A';
            }
            if (s[i] >= 'a' and s[i] <= 'z') {
                idx = s[i] - 'a';
            }
            if (idx >= 0) {
                a[idx]++;
                mx = max(mx, a[idx]);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] == mx) {
                cout << (char)('a' + i);
            }
        }
        cout << "\n";
    }
    return 0;
}