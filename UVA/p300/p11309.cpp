//11309
#include<bits/stdc++.h>
using namespace std;

int rev(int n){
    int tmp = 0;
    while(n){
        tmp*=10;
        tmp+=n%10;
        n/=10;
    }
    return tmp;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int h,m;
        char c;
        cin >> h >> c >> m;
        int n = h*100+m;
        for(n++; ; n++){
            if(n == 2360){
                n = 0;
            }
            if(n % 100 == 60){
                n = ((n/100)+1)*100;
            }
            if(rev(n) == n){
                cout <<setw(2)<<setfill('0') << n/100 << ":" <<setw(2)<<setfill('0')<< n%100 << '\n';
                break;
            }
        }
    }
}