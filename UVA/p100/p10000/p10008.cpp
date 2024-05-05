//10008
#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int first;
    char second;
	bool operator <(const Edge& y) const { if(first == y.first)return second < y.second;
         else return first > y.first;
    }
};

int main(){
    string s;
    int n;
    map<char,int>mp;
    set<Edge>st;
    cin >> n;
    while(getline(cin,s)){
        int i = 0;
        for(; i < s.length(); i++){
            if((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a')){
                mp[toupper(s[i])]++;
            }
        }
    }
    for(auto i :mp){
        st.insert({i.second,i.first});
    }
    for(auto i :st){
        cout << i.second << " " << i.first << endl;
    }
}