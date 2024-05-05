//10176
#include <iostream>

using namespace std;

int main() {
    char s;
    int ans = 0;
    while(cin >> s) 
    {
        if(s == -1)break;
        else if(s == '#') 
        {
            if(ans)cout << "NO";
            else cout << "YES";
            cout << endl;
            ans = 0;
        }
        else
        {
            ans = (ans << 1) + s - '0';
            ans %= 131071;
        } 
    }
}