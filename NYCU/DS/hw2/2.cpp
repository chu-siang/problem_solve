#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    queue<int>q;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> num;
        q.push(num);
    }
    stack<int>tmp;
    for(int i = 1; i <= n; i++){
        if(!tmp.empty()){
            while(q.front() == tmp.top()){
                tmp.pop();
                q.pop();
                if(tmp.empty() || q.empty()){
                    break;
                }
            }
        }
        tmp.push(i);
    }
    while(tmp.size()){
        if(tmp.top() == q.front()){
            q.pop();
            tmp.pop();
        }else{
            break;
        }
    }
    if(q.size() || tmp.size())cout << "NO\n";
    else cout << "YES\n";
}