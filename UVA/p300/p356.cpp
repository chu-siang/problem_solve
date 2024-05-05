//uva356
#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ll n;
    bool flag =false;
    while(cin >> n){
        double r = n-0.5;
        ll c = 0,p = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                double a = sqrt(x*x + y*y),b = sqrt((x+1)*(x+1)+(y+1)*(y+1));
                if(b <= r)c++;
                else if(a < r)p++;
            }
        }
        if(flag)cout<<'\n';
        else flag = true;
        cout << "In the case n = " << n << ", "<< p*4 << " cells contain segments of the circle.\n";
        cout <<"There are "<< c*4 << " cells completely contained in the circle.\n";
    }
}