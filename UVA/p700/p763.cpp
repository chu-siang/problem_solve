#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[110] = {0};

int main(){
    string s1,s2;
    bool flag = false;
    while(cin >> s1){
        cin.ignore();
        cin >> s2;
        if(flag)cout << '\n';
        flag = true;
        memset(a,0,sizeof(a));
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int len2 = s2.length();
        int len1 = s1.length();
        a[0] = 0;
        a[1] = 0;
        for(int i = 2, j = 2; i < len1 + 2 || j < len2 + 2; i++, j++){
            if(i < (len1 + 2))a[i] += (s1[i-2]-'0');
            if(j < (len2 + 2))a[j] += (s2[j-2]-'0');
        }
        while(1){
            for(int i = 107; i >= 2; i--){
                while(a[i] > 1){
                    a[i + 1] += (a[i]/2);
                    if(i == 3)a[i-1]+= (a[i]/2);
                    if(i >= 4)a[i - 2] += (a[i]/2);
                    a[i] %= 2;
                }
                if(a[i] == 1 && a[i-1] == 1){
                    a[i] = a[i-1] = 0;
                    a[i + 1] += 1;
                }
            }
            int b = 0;
            for(int i = 107; i >= 2; i--){
                b += (a[i] >= 2);
                while(a[i] > 1){
                    a[i + 1] += (a[i]/2);
                    if(i == 3)a[i-1]+=(a[i]/2);
                    if(i >= 4)a[i - 2] += (a[i]/2);
                    a[i] %= 2;
                }
                if(a[i] == 1 && a[i-1] == 1){
                    a[i] = a[i-1] = 0;
                    a[i + 1] += 1;
                    b = 2;
                }
            }
            if(b == 0)break;
        }
        
        bool flag2 = false;
        for(int i = 107; i >= 2; i--){
            if(a[i] == 1)flag2 = true;
            if(flag2)cout << a[i];
        }
        if(!flag2)cout << '0';
        cout << '\n';
    }
}