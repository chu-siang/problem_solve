//356
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    double n;
    while(cin >> n){
        double r = (2*n-1)/2;
        ll c = 0,s = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i+1)*(i+1) + (j+1)*(j+1) <= r*r)c++;
                else if(i*i + j*j < r*r)s++;
            }
        }
        cout << "In the case n = " << n << ", " << s*4 <<" cells contain segments of the circle.\n";
        cout << "There are " << c*4 << " cells completely contained in the circle.\n";
        cout << '\n';
    }
}