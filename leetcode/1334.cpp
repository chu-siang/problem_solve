class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>w(n,vector<int>(n,INT_MAX/2));
        for(auto i : edges){
            int v = i[0], e = i[1], k  = i[2];
            w[v][e] = w[e][v] = k;
        }
        auto f = std::move(w);
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        int ans = 0, mn = n;
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = 0; j < n; ++j){
                if(i!=j && f[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(mn >= cnt){
                mn = cnt;
                ans = i;
            }
        }
        return ans;
    }
};