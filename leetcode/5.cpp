class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        // 1. 預處理：插入 #
        string t;
        t.reserve(2 * n + 1);
        for (int i = 0; i < n; ++i) {
            t.push_back('#');
            t.push_back(s[i]);
        }
        t.push_back('#');

        int m = t.size();
        vector<int> p(m, 0);

        int center = 0, right = 0;
        int bestLen = 0, bestCenter = 0;

        // 2. Manacher 主迴圈
        for (int i = 0; i < m; ++i) {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            // 嘗試擴展
            while (i - p[i] - 1 >= 0 &&
                   i + p[i] + 1 < m &&
                   t[i - p[i] - 1] == t[i + p[i] + 1]) {
                ++p[i];
            }

            // 更新右界
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            // 更新答案
            if (p[i] > bestLen) {
                bestLen = p[i];
                bestCenter = i;
            }
        }

        // 3. 還原回原字串 index
        int start = (bestCenter - bestLen) / 2;
        return s.substr(start, bestLen);
    }
};
