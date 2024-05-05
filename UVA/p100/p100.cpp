#include<iostream>
using namespace std;

int R(int i){
    int count=1;
    while(i!=1){
        i = ((i&1) ? i*3+1 : i/2);
        count++;
    }
    return count;
}
int main(){
    int l,r;
    while(cin>>l>>r && l != 0){
        int Ans=1;
        for(int i=min(l,r);i<=max(l,r);i++)Ans=max(Ans,R(i));
        cout<<l<<" "<<r<<" "<<Ans<<endl;
    }
}