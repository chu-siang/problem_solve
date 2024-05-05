#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int MAXN = 1e8+5;
ull arr[MAXN] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ull s,d;
    while(cin >> s >> d){
        if(s >= d){
            cout << s << '\n';
            continue; 
        }
        
        arr[0] = s;
        for(ull i = 1; i <= 1e8+5; i++){
            arr[i] = (arr[i-1] + i+s);
            if(arr[i] >= d){
                cout << i+s << '\n';
                break;
            }
        }
    }
}
