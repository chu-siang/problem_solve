#include<iostream>
#include<cmath>
#include<array>
#include<deque>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        if(n<4){
            cout<<"-1"<<endl;
            continue;
        }
        deque<int> dq{3,1,4,2};
        for(int i = 5; i <= n; i++){
            if(i % 2)
                dq.push_back(i);
            else dq.push_front(i);
        }
        for(int it : dq)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
