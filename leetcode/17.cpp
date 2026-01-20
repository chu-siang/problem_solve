class Solution {
public:
    vector<string>res;
    void dfs(vector<string>number , string digits, int idx, int r,string tmp){
        if(idx >= r){
            res.push_back(tmp);
            return ;
        }
        string s = number[digits[idx]-'0'];
        for(int i = 0; i < s.size(); ++i){
            tmp+=s[i];
            dfs(number,digits,idx+1,r,tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>number = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int r = digits.size();
        dfs(number,digits,0,r,"");
        return res;
    }
};
