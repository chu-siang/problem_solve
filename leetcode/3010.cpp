class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(next(nums.begin()), nums.end());
        return nums[0]+nums[1]+nums[2];
    }
};