#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string str1,str2;
    while(getline(cin,str1),getline(cin,str2)){
        stringstream ss1(str1);
        stringstream ss2(str2);
        set<int>s1,s2;
        int num;
        while(ss1 >> num) s1.emplace(num);
        while(ss2 >> num) s2.emplace(num);
        // 1 3 5 6
        // 1 5 6
        if(s1.size() > s2.size()){
            int com = 0;
            for(auto i = s2.begin(); i != s2.end(); i++){
                if(s1.count(*i))com++;
            }
            if(com == 0)cout <<"A and B are disjoint\n";
            else if(com == s2.size())cout << "B is a proper subset of A\n";
            else cout << "I'm confused!\n";
        }else if(s1.size() < s2.size()){    
            int com = 0;
            for(auto i = s1.begin(); i != s1.end(); i++){
                if(s2.count(*i))com++;
            }
            if(com == 0)cout <<"A and B are disjoint\n";
            else if(com == s1.size())cout << "A is a proper subset of B\n";
            else cout << "I'm confused!\n";
        }else{
            int com = 0;
            for(auto i = s1.begin(); i != s1.end(); i++){
                if(s2.count(*i))com++;
            }
            if(com == s1.size())cout << "A equals B\n";
            else cout << "I'm confused!\n";
        }
    }
}