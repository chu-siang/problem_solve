#include<bits/stdc++.h>
using namespace std;


signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cin.ignore();
        int x = 0;
        vector<int>v(n+1);
        for(int i = 1; i <= n; i++){
            string s;
            getline(cin, s);
            if(s[0] == 'L')v[i] = -1;
            else if(s[0] == 'R')v[i] = 1;
            else {
                stringstream ss;
                ss << s;
                string temp1,temp2;
                int num;
                ss >> temp1 >> temp2 >> num;
                v[i] = v[num];
                ss.clear();
                ss.str("");
            }
            x+=v[i];
        }
        cout << x << '\n';
    }
}