#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--){
        map<string,long long> mp;
        string s;
        long long c = 0;
        while(getline(cin, s) && s != ""){
            mp[s]++;
            c++;
        }
        for(auto i : mp) cout << i.first << " " << fixed << setprecision(4) << 100 *(i.second/(double)c)  << '\n';
        if(n)cout << '\n';
    }
}
/*#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    
    map<string,double>mp;
    cin.ignore();
    cin.ignore();
    while(t--){
        double count = 0.0;
        string s;
        while(getline(cin,s)){
            if(s=="")break;
            mp[s]++;
            count++;
        }
        for(auto [a,b] : mp){
            cout << a << ' ' << fixed << setprecision(4) << (b/count*100) << '\n';
        }
        cout << "\n"[t==0];
        mp.clear();
    }
    
    return 0;
}*/