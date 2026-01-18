class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = n/2;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; ++i){
            mp[nums[i]]++;
            if(mp[nums[i]] > cnt)return nums[i];
        }
        int mx = -1e9, ans = 0;
        for(auto i : mp){
            if(i.second > ans){
                ans = i.second;
                mx = i.first;
            }
        }
        return mx;
    }
};