#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a[4];
        for(int i = 0; i < 4; i++)cin >> a[i];
        sort(a,a+4);
        if(a[0] == 0){
            cout << "banana\n";
            continue;
        }
        if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) cout << "square";
        else if(a[0] == a[1] && a[2] == a[3])cout <<"rectangle";
        else if(a[0] + a[1] + a[2] > a[3])cout << "quadrangle";
        else cout << "banana";
        cout << '\n';
    }
}