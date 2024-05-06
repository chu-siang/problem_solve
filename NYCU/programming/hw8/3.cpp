//uva 12019 a065
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int m,d;
    string s[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int a[13];
    a[1] = 10, a[2] = 21, a[3] = 7, a[4] = 4;
    a[5] = 9, a[6] = 6, a[7] = 11, a[8] = 8;
    a[9] = 5, a[10] = 10, a[11] = 7, a[12] = 12;
    int n;
    cin >> n;
    while(n--){
        cin >> m >> d;
        cout << s[(d -a[m]+ 35)%7] << '\n';
    }
}
