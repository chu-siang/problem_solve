#include<bits/stdc++.h>
using namespace std;

bool pixel(int &a,int &b,int &c,char color){
    switch(color){
        case 'M':
            if(a==0)return false;
            --a;
            break;

        case 'W':
            break;

        case 'Y':
            if(b==0)return false;
            --b;
            break;

        case 'C':
            if(c==0)return false;
            --c;
            break;

        case 'R':
            if(a==0 || b==0)return false;
            --a;
            --b;
            break;
        
        case 'G':
            if(b==0 || c==0)return false;
            --c;
            --b;
            break;

        case 'V':
            if(a==0||c==0)return false;
            --c;
            --a;
            break;

        case 'B':
            if(a==0||b==0||c==0)return false;
            --c;
            --a;
            --b;
            break;
    }
    return true;
}



int main(){
    int n;
    cin>>n;


    while(n--){
        int m,y,c;
        cin>>m>>y>>c;
        string s;
        cin>>s;
        int l=s.length();
        bool ok=true;
        for(int i=0;i<l;++i){
            ok=pixel(m,y,c,s[i]);
            if(!ok)break;
        }
        if(!ok)cout<<"NO"<<endl;
        else cout<<"YES "<<m<<" "<<y<<" "<<c<<endl;
    }
}