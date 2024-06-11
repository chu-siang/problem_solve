#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line{
    int start;
    int end;
};

bool compare(line &a, line &b){
    return a.start<b.start;
}

int main(){
    string s1, s2;
    vector<line>dp;
    while(cin>>s1 && s1!="."){
        cin>>s2;
        line l;
        int temp = 0;
        for(int i = 0; i<s1.size(); i++){
            temp *= 10;
            temp += s1[i]-'0';
        }
        l.start = temp;
        temp = 0;
        for(int i = 0; i<s2.size(); i++){
            temp *= 10;
            temp += s2[i]-'0';
        }
        l.end = temp;
        dp.push_back(l);
    }
    sort(dp.begin(), dp.end(), compare);
    int ans = 0;
    for(int i = 0; i<dp.size(); i++){
        cout<<dp[i].start<<" "<<dp[i].end<<"\n";
    }
    for(int i = 1; i<dp.size(); i++){
        if(dp[i].start < dp[i-1].end){
            if(dp[i].end < dp[i-1].end) ans += (dp[i].end-dp[i].start);
            else ans += (dp[i-1].end-dp[i].start);
        }
    }
    cout<<ans<<"\n";
    return 0;
}