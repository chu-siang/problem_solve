class Solution {
    public:
        string countAndSay(int n) {
            string s = "1";
            for(int i = 1; i < n; ++i){
                int count = 1;
                string ans = "";
                for(int j = 1; j < s.length(); ++j){
                    if(s[j] == s[j-1]){
                        count++;
                    }else{
                        ans += to_string(count) + s[j-1];
                        count = 1;
                    }
                }
                ans += to_string(count) + s.back();
                s = ans;
            }
            return s;
        }
    };