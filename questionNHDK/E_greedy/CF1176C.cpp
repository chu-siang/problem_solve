#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
int a[MAXN];
int f[100];
int main(){
    int n;
    cin >> n;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> num;
        if(num == 4)a[i] = 1;
        else if(num == 8) a[i] = 2;
        else if(num == 15)a[i] = 3;
        else if(num == 16)a[i] = 4;
        else if(num == 23)a[i] = 5;
        else a[i] = 6; 
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            f[1]++;
        }
        else{
            if(f[a[i]-1]){
                f[a[i]]++;
                f[a[i]-1]--;
            }
        }
    }
    cout << n-6*f[6];
}