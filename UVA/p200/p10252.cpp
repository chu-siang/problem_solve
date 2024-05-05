#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    string s1,s2;
    while(getline(cin,s1)){
        getline(cin,s2);
        int count1[40] = {0};
        int count2[40] = {0};
        for(int i = 0; i < s1.size(); i++){
            count1[s1[i] -'a']++;
        }
        for(int j = 0; j < s2.size(); j++){
            count2[s2[j] -'a']++;
        }
        for(int i = 0; i < 26; i++){
            for(int j = min(count1[i],count2[i]); j > 0; j--)
                cout << (char)('a'+i);
        }
        cout << '\n';
    }
    return 0;
}
