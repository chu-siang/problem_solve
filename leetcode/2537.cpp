class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int good = 0;
            int n = nums.size();
            unordered_map<int,int> mp;
            int right = -1;
            int same = 0;
            for(int i = 0; i < n; ++i){
                while(same < k && right + 1 < n){
                    right++;
                    same += mp[nums[right]];
                    mp[nums[right]]++;
                }
                if(same >= k)good += n - right;
                --mp[nums[i]];
                same -= mp[nums[i]];
            }
            return good;
        }
    };