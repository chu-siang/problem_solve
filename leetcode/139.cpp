class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0)return false;
        set<string>st;
        for(auto i : wordDict)st.emplace(i);
        int sz = s.size();
        vector<bool>dp(sz+1,false);
        dp[0] = true;
        for(int i = 1; i <= sz; ++i){
            for(int j = i - 1; j >= 0; j--){
                if(dp[j]){
                    string sub_s = s.substr(j,i-j);
                    if(st.find(sub_s)!= st.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[sz];
    }
};