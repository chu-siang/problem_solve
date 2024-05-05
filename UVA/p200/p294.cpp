#include<iostream>
#include<cmath>
#include<vector>
typedef long long ll;
using namespace std;

vector<int> v;
int prime[32000];

int main(){
    int n;
    cin>>n;
    
    for(int i=2;i<32000;i++){
        if(prime[i]==0){
            v.push_back(i);
            for(int j=i*2;j<32000;j+=i){
                prime[j]=1;
            }
        }
    }
    
    ll a,b;
    while(n--){
        cin>>a>>b;
        ll max=0;
        ll ind=0;
        for(ll i=a;i<=b;i++){
            ll q=i;int cnt=1;
            for(auto &c:v){
                int pnt=0;
                while(q%c==0){
                    q/=c;
                    pnt++;
                }
                cnt*=(pnt+1);
                if(q==1)break;
            }
            if(cnt>max){
                max=cnt;
                ind=i;
            };
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<ind<<" has a maximum of "<<max<<" divisors."<<endl;
    }
    return 0;
}