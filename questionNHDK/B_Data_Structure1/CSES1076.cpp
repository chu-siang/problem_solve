#include<iostream>
#include<set>
#define int long long
using namespace std;

int x[200005];

void balance(multiset<int, greater<int>> &left, multiset<int, less<int>> &right){
    while(left.size() > right.size()){
        right.insert(*left.begin());
        left.erase(left.begin());
    }
    while(left.size() < right.size()){
        left.insert(*right.begin());
        right.erase(right.begin());
    }
    return ;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    multiset<int, greater<int>> left;
    multiset<int, less<int>> right;
    for(int i = 0; i < n; i++){
        if(!left.size() || x[i] <= *left.begin()){
            left.insert(x[i]);
        }
        else {
            right.insert(x[i]);
        }
        if(i >= m){
            if(left.size() && x[i-m] <= *left.begin())
                left.erase(left.find(x[i-m]));
            else
                right.erase(right.find(x[i-m]));
        }
        balance(left, right);
        if(i >= m-1)
            cout << *left.begin() << " ";
    }
    cout << '\n';
    return 0;
}