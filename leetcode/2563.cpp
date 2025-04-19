class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(),nums.end());
            return findV(nums,upper + 1) - findV(nums, lower);
        }
    private: 
        long long findV(vector<int>& nums, int val){
            long long result = 0;
            int l = 0, r = nums.size()-1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum < val){
                    result += r - l;
                    l++;
                }else{
                    r--;
                }
            }
            return result;
        }
    };