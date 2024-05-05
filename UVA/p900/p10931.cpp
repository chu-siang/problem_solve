#include<bits/stdc++.h>
using namespace std;

int main(){
    int  i,count;
    while(cin >> i, i){
        count = 0;
        string s = "";
        while(i){
            if(i&1) count++;
            s = to_string(i&1) + s;//to_string
            i /= 2;
        }
        cout << "The parity of " << s << " is " << count << " (mod 2)." << endl;
    }
}

/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 105;
ll cnt = 0;
string bin(int t){
    if(t == 1){
        cnt++;
        return "1";
    }
    else if(t == 0) return "0";
    return bin(t/2)+bin(t&1);
}


int main(){
    ll t;
    while(cin >> t,t){
        cnt = 0;
        cout <<"The parity of "<< bin(t) <<" is "<< cnt << " (mod 2).\n";
    }
}
*/