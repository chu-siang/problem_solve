#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++){
        int n;
        cin >> n;
        map<int,int>mp;//前面是人 后面是编号
        map<int,deque<int>>coffee;
        int k,num;
        queue<int>q;
        for(int i = 1; i <= n; i++){
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> num;
                mp[num] = i;
            }
        }
        int m;
        cin >> m;
        string s;
        cin.ignore();
        int Line = n+1;
        cout << "Testcase #" << c << '\n';
        while(m--){
            cin >> s;
            if(s[0] == 'E'){
                int p;
                cin >> p;
                cin.ignore();
                if(mp[p] && coffee[mp[p]].empty()){
                    coffee[mp[p]].push_back(p);
                    q.push(mp[p]);
                }else if(mp[p] && !coffee[mp[p]].empty()){
                    coffee[mp[p]].push_back(p);
                }else{
                    //no group
                    q.push(Line);
                    coffee[Line].push_back(p);
                    Line++;
                }
            }else if(s[0] == 'D'){
                int people = q.front();
                cout << coffee[people].front() << '\n';
                coffee[people].pop_front();
                if(coffee[people].empty()){
                    q.pop();
                }
            }
        }
    }
}