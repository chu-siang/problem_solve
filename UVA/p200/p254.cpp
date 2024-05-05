#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll  t=0;
ll  a;
void honai(int n, ll* source, ll* dest, ll* tmp,int k) {
    if (n == 1) {
        t++;
        (*dest)++;
        (*source)--;
    } else { 
        honai(n-1, source, tmp, dest,k);
        if (t==k){
            cout<<(*source)<<" "<<(*tmp)<<" "<<(*dest)<<endl;
            return ;
        }
        t++; 
        (*dest)++;
        (*source)--;
        honai(n-1, tmp, dest, source,k);
    }
  return ;
}

/*
void honoi(ll *source,ll *tmp, ll *dest ,ll n ,ll k){
    if(n==1){
            t++;
            (*dest)++;
            (*source)--;
            if (t==k){
                cout<<(*source)<<" "<<(*tmp)<<" "<<(*dest)<<" t= "<<t<<"     n="<<n<<endl;
                return ;
            }
    }else{
        honoi(source,dest,tmp,n-1,k);
            t++;
            (*dest)++;
            (*source)--;
        if (t==k){
            cout<<(*source)<<" "<<(*tmp)<<" "<<(*dest)<<endl;
            return ;
        }
        honoi(tmp,source,dest,n-1,k);
    }
    return ;
}

*/
int main(){
    ll  b;
    while(cin>>a>>b){
        if(a==b &&b==0)break;
        ll  cc=0;
        ll  d=0;
        int l=a;
        honai(l,&a,&d ,&cc,b);
        t=0;
    }
    return 0;
}
