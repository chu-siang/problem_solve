#include<iostream>
#include<vector>
#define MAXN 1005
#define int long long
using namespace std;

int n,m;

struct Data{
    int s, t, cnt;

} x[MAXN];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>x[i].s;
        x[i].cnt=0;
    }
    for(int i=1;i<=n;++i){
        cin>>x[i].t;
    }
    vector<int>v;
    for(int i=1,a;i<=n;i++){
        cin>>a;
        v.push_back(a);
    }
    while(v.size()>1){
        vector<int>win,lose;
        for(int i=0;i<v.size();i+=2){
           if(i==v.size()-1){
                win.push_back(v[i]);
                break;
            }
            long long  a=x[v[i]].s;
            long long  b=x[v[i]].t;
            long long  c=x[v[i+1]].s;
            long long  d=x[v[i+1]].t;
            if(a * b >= c * d){
                x[v[i]].s = a + c * d / ( 2 * b );
                x[v[i]].t = b + c * d / ( 2 * a );
                x[v[i + 1]].s = c + c / 2,
                x[v[i + 1]].t = d + d / 2;
                x[v[i + 1]].cnt++;
                if(x[v[i + 1]].cnt < m){
                    lose.push_back(v[i+1]);
                }
                win.push_back(v[i]);
            }else{
                x[v[i + 1]].s = c + a * b / ( 2 * d ),
                x[v[i + 1]].t = d + a * b / ( 2 * c );
                x[v[i]].s = a + a / 2;
                x[v[i]].t = b + b / 2;
                x[v[i]].cnt++;
                if(x[v[i]].cnt < m){

                    lose.push_back(v[i]);
                }
                win.push_back(v[i + 1]);
            }
        }
        v.clear();
        for(int &i:win){
                v.push_back(i);
            }
        for(int &i:lose){
            v.push_back(i);
        }
    }
    cout<<v[0];
}