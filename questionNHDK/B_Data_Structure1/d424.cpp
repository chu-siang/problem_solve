#include<iostream>
using namespace std;

int skyline[10005]={0};


int main(){
    int l, ltest = 1e6, r, h, rtest = 0;
    while(cin >> l >> h >> r ){
        for(int i = l; i < r; i++){
            if(h > skyline[i]) skyline[i] = h;
        }
        if(l < ltest) ltest = l;
        if(r > rtest) rtest = r;
    }
    bool flag = false;
    for(int i = ltest; i <= rtest; i++){
        if(skyline[i-1] != skyline[i]){
            if(flag) cout <<" ";
            flag = true;
            cout << i << " " << skyline[i];
        }
    }
    cout << endl;
    return 0;

}