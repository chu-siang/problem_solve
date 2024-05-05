#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    map<int,int>mp;
    //monday;
    mp[1] = 10,mp[2] = 21,mp[3] = 7,mp[4] = 4;
    mp[5] = 9,mp[6] = 6,mp[7] = 11,mp[8] = 8;
    mp[9] = 5,mp[10] = 10, mp[11] = 7,mp[12] = 12;
    string w[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    cin >> t;
    while(t--){
        int m,d;
        cin >> m >> d;
        cout << w[(d - mp[m] +35)%7] << '\n';
    }
}