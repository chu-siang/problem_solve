#include<bits/stdc++.h>
#define int long long
using namespace std;
int half,total,n;
set<set<int>>ans;
map<int,vector<set<int>>>mp;//sum, sum's combination
void dfs1(int idx,vector<int>&v,int sum,set<int>st){
    if(idx == n/2){
        if(sum == 0)return;
        mp[sum].push_back(st);
        return;
    }
    dfs1(idx+1,v,sum,st);
    st.emplace(v[idx]);
    dfs1(idx+1,v,sum+v[idx],st);
}
//1 2 3
//1 2 3 6
//
void dfs2(int idx,vector<int>&v,int sum,set<int>st){
    if(idx == n){
        if(mp.count(half - sum)){
            for(int i = 0; i < mp[half-sum].size(); i++){
                set<int>st1(mp[half-sum][i]);
                for(auto i:st){
                    st1.emplace(i);
                }
                bool f[n] = {0};
                set<int>st2;
                for(auto i:v){
                    if(!(st1.count(i))){
                        st2.emplace(i);
                    }
                }
                ans.emplace(st1);
                ans.emplace(st2);
            }
        }
        return;
    }
    dfs2(idx+1,v,sum,st);
    st.emplace(v[idx]);
    dfs2(idx+1,v,sum+v[idx],st);
}
bool cmp(set<int> a,set<int> b){
    return a.size() < b.size();
}
signed main() {
    char c;
    while (cin >> c) {
        if(c == '.')break;
        string s;
        getline(cin,s);
        stringstream ss(s);
        vector<int> arr;
        arr.clear();
        int num;
        total = 0;
        while (ss>> num) {
            arr.push_back(num);
            total+=num;
        }
        ss.clear();
        ss.str("");
        n = (int)arr.size();
        sort(arr.begin(),arr.end());
        half = total/2;
        set<int>st;
        mp.clear();
        ans.clear();
        dfs1(0,arr,0,st);
        st.clear();
        dfs2(n/2,arr,0, st);
        if (ans.empty()) {
            cout << "No such subset" << '\n';
        } else {
            vector<set<int>>out;
            for(auto i:ans){
                out.push_back(i);
            }
            cout << out.size() << " subsets." << '\n';
            sort(out.begin(), out.end(),cmp);
            for (auto element : out) {
                vector<int>pr;
                for (auto i:element) {
                    pr.push_back(i);
                }
                cout << '{';
                for(int i = 0; i < pr.size(); i++){
                    cout << pr[i] << " }"[i==pr.size()-1];
                }
                cout << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}