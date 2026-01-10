class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0, start = -1;
        int dic[256]={0};
        fill(dic,dic+256,-1);
        for(int i = 0; i < s.length();i++){
            if(dic[s[i]] > start){
                start = dic[s[i]];
            }
            dic[s[i]] = i;
            length = max(length, i - start);

        }
        return length;
    }
};