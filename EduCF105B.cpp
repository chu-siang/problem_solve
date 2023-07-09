#include<iostream>

using namespace std;

int n;

bool check(int x){
    if(x >= 0 && x <= n - 2) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        int u,r,d,l;
        cin >> n >> u >> r >> d >> l;
        int f = 0;
        for(int i1 = 0; i1 < 2; i1 ++)
            for(int i2 = 0; i2 < 2; i2 ++)
                for(int i3 = 0; i3 < 2; i3 ++)
                    for(int i4 = 0; i4 < 2; i4 ++){
                        if(check(u - i1 - i2) && check(r - i2 - i3) && check(d - i3 - i4) && check(l - i4 - i1)) f = 1;
                    }
        if(f) cout << "YES";
        else cout << "NO";
    }
}
/*#include<iostream>
using namespace std;

int main(){
    int U, R, D, L;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n >> U >> R >> D >> L;
        bool flag = false;
        for(int i = 0; i <= 1 ;i ++){
            for(int j = 0; j <= 1; j++){
                for(int k = 0; k <= 1; k++){
                    for(int l = 0; l <= 1; l++){
                        if(U - i - j >= 0 && R - j - k >= 0 && D - k - l >= 0 && L - l - i >= 0 ){
                            if(U - i - j > n - 2) continue; 
                            if(R - j - k > n - 2) continue;
                            if(D - k - l > n - 2) continue;
                            if(L - l - i > n - 2) continue;
                            flag = true;
                        }
                    }
                }
            }
        }
        if(flag) cout << "YES" <<'\n';
        else cout << "NO" << '\n';
    }
}
*/