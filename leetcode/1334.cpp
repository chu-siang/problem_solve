class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector w(n, vector<int>(n, INT_MAX / 2)); // avoid overflow
        for (auto& e: edges) {
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = w[y][x] = wt;
        }

        vector memo(n, vector(n, vector<int>(n)));
        auto dfs = [&](this auto&& dfs, int k, int i, int j) -> int {
            if (k < 0) { 
                return w[i][j];
            }
            auto& res = memo[k][i][j]; // reference
            if (res) { // calculate before
                return res;
            }
            return res = min(dfs(k - 1, i, j), dfs(k - 1, i, k) + dfs(k - 1, k, j));
        };

        int ans = 0;
        int min_cnt = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && dfs(n - 1, i, j) <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= min_cnt) { // equal and 
                min_cnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};