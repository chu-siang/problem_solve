#include<bits/stdc++.h>
#include<deque>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n && n){
        if(left.empty() || n < left.top())
            left.push(n);
        else
            right.push(n);
        
        while(left.size() > right.size()){
            right.push(left.top());
            left.pop();
        }
        while(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        if(right.size() == left.size()){
            cout << (left.top() + right.top()) / 2 << '\n';    
        }else cout << left.top() << '\n';
    }   
    
    return 0;
}

