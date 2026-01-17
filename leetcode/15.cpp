class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3)return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int target = 0;
        for(int i = 0; i < nums.size() - 2; ++i){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int j = i + 1, k = nums.size()-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j + 1 < k && nums[j]==nums[j+1])j++;
                    while(j + 1 < k && nums[k]==nums[k-1])k--;
                    j++,k--;
                }
                else if(nums[i] + nums[j] + nums[k] > target)k--;
                else j++;
            }
        }
        return ans;
    }
};