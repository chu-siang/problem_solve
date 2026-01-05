class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char>s1,s2;
        for(auto c : s)s1.emplace(c);
        for(auto c : t)s2.emplace(c);
        if(s1 == s2)return true;
        return false;
    }
};