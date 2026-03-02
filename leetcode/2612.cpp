class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
       unordered_set<int>ban(banned.begin(),banned.end());
       set<int>indices[2];
       for(int i = 0; i < n; ++i){
            if(i != p && !ban.contains(i)){
                indices[i%2].insert(i);
            }
       }
       queue<int>q;
       q.push(p);
       vector<int>ans(n,-1);
       ans[p] = 0;
       while(q.size()){
        int i = q.front(),q.pop();
        int mn =  max(i - k + 1, k - 1 - i);
        int mx = min(i + k - 1,2 * n - k - i - 1);
        auto &st = indices[i % 2];
        for(auto it = st.lower_bound(mn); *it <= mx; it = st.erase(it)){
            ans[*it] = ans[i] + 1;
            q.push(*it);
        }
       }
       return ans;
    }
};