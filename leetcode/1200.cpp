class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int mn = 1e7;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0; i < n - 1; ++i){
            if(abs(arr[i+1] - arr[i]) < mn){
                ans.clear();
                mn = abs(arr[i+1] - arr[i]);
                ans.push_back({arr[i],arr[i+1]});
            }else if(abs(arr[i+1] - arr[i]) == mn){
                ans.push_back({arr[i],arr[i+1]}); 
            }
        }
        return ans;
    }
};