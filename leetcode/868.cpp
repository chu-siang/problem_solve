class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        n /= (n & -n)*2;
        while(n > 0){
            int gap = countr_zero((uint32_t)n)+1;
            ans = max(ans,gap);
            n >>= gap;
        }      
        return ans;
    }
};