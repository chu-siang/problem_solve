#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t,n;
bool a[20][7] = {0};
void Digit(int i,int len){
    for(int j = 0; j < len; j++){
        cout << " ";
        if(a[j][i]){
            for(int k = 0; k < t; k++)
                cout << "-";
            }else{
                for(int k = 0; k < t; k++)
                    cout << " ";
        }
        cout << " ";
        if(j < len-1)cout << " ";//between digit
    }
    cout << '\n';
}

int main(){
    bool cd[10][7] = {
        {1,1,1,0,1,1,1},
        {0,0,1,0,0,1,0},
        {1,0,1,1,1,0,1},
        {1,0,1,1,0,1,1},
        {0,1,1,1,0,1,0},
        {1,1,0,1,0,1,1},
        {1,1,0,1,1,1,1},
        {1,0,1,0,0,1,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1}
    };
    while(cin >> t >> n){
        if(t == n && n == 0)break;
        memset(a,0,sizeof(a));
        stringstream ss;
        ss << n;
        string s;
        ss >> s;
        int len = s.length();
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < len; j++){
                a[j][i] = cd[s[j]-'0'][i];
            }
        }
        Digit(0,len);
        for(int i = 0; i < t; i++){
            for(int j = 0; j < len; j++){
                if(a[j][1]){
                    cout << "|";
                    for(int k = 0; k < t; k++)
                        cout << " ";
                }else{
                    cout << " ";
                    for(int k = 0; k < t; k++)
                        cout << " ";
                }
                if(a[j][2]){
                    cout << "|";
                }else{
                    cout << " ";
                }
                if(j < len-1)cout << " ";//between digit
            }
            cout << '\n';
        }
        Digit(3,len);
        for(int i = 0; i < t; i++){
            for(int j = 0; j < len; j++){
                if(a[j][4]){
                    cout << "|";
                    for(int k = 0; k < t; k++)
                        cout << " ";
                }else{
                    cout << " ";
                    for(int k = 0; k < t; k++)
                        cout << " ";
                }
                if(a[j][5]){
                    cout << "|";
                }else{
                    cout << " ";
                }
                if(j < len-1)cout << " ";//between digit
            }
            cout << '\n';
        }
        Digit(6,len);
        cout << '\n';
        ss.str("");
        ss.clear();
    }
}