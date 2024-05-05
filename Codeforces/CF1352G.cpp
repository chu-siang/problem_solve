#include<iostream>
#include<cmath>
#include<array>
#include<deque>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        size_t arr[]={3,1,4,2};
        deque<int>dq;
        int n;
        cin>>n;
        if(n<4){
            cout<<"-1"<<endl;
            continue;
        }
        if(n==4){
            cout<<"3 1 4 2"<<endl;
            continue;
        }
        auto it=dq.begin();
        dq.insert(it,arr,arr+(sizeof(arr)/sizeof(int)));
        for(int i=5;i<=n;i++){
            if(i%2==0)dq.push_back(i);
            else if(i%2==1)dq.push_front(i);
        }
        int i=0;
        for(int l=dq.size();i<l;i++){
            cout<<dq[i]<<" \n"[i==l-1];
        }
        dq.clear();
    }
    return 0;
}
