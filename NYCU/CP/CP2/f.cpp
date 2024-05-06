//Same Digits (Hard)
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Digit{
    int x,y,xy;
};

signed main(){
    int a,b;
    cin >> a >> b;
    vector<Digit>v;
    int num[11];
    for(int i = a; i <= b; i++){
        for(int j = i + 1; j*i <= b; j++){
            memset(num,0,sizeof(num));
            int tmpa = i, tmpb = j;
            while(tmpa){
                num[tmpa%10]++;
                tmpa/=10;
            }
            while(tmpb){
                num[tmpb%10]++;
                tmpb/=10;
            }
            tmpa = i*j;
            while(tmpa){
                num[tmpa%10]--;
                tmpa/=10;
            }
            bool flag = true;
            for(int i = 0; i <= 10; i++){
                if(num[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                Digit tmp;
                tmp.x = i,tmp.y = j,tmp.xy = i*j;
                v.push_back(tmp);
            }
        }
    }
    cout << v.size() << ' ' << "digit-preserving pair(s)\n";
    if(v.size()){
        for(auto i:v){
            cout << "x = " << i.x << ", y = " << i.y << ", xy = " << i.xy << '\n';
        }
    }
}