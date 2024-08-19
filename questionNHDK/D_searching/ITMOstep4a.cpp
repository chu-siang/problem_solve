#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    double l = 0.0, r = 100.0;
    for(int i = 0; i <= 100; i++){
        double mid = (l + r)/2.0;
        double mn = 0;
        vector<double> v(n+1,0.0);
        bool check = false;
        for(int j = 0; j < n; j++){
            if(j + 1 -d >= 0){
                if(v[j + 1 - d] < mn)mn = v[j + 1 - d];
            }
            v[j + 1] = v[j] + (a[j]-mid);
            if(v[j+1] - mn >= 0 && j - d + 1 >= 0){
                check = true;
            }
        }
        if(check) l = mid;
        else r = mid;
    }
    double ans = r;
    vector<double> v(n+1,0.0);
    double mn = 0;
    int idx = 0;
    double eps = 1e-6;
    for(int i = 0; i < n; i++){
        if(i - d + 1 >= 0){
            if(v[i + 1 - d] < mn) mn = v[i + 1 -d] ,idx = i + 1 -d;
        }
        v[i + 1] = v[i] + (a[i] - r);
        if(v[i + 1] - mn + eps >= 0 && i + 1 - d >= 0){
            cout << idx + 1 << " " << i + 1 <<endl;
            exit(0);
        }
    }
}