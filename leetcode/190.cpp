class Solution {
public:
    int reverseBits(int n) {
        static constexpr uint32_t m1 = 0x00ff00ff; 
        static constexpr uint32_t m2 = 0x0f0f0f0f;
        static constexpr uint32_t m3 = 0x33333333;
        static constexpr uint32_t m4 = 0x55555555;
        
        n = n >> 16 | n << 16;
        n = n >> 8 & m1 | (n & m1) << 8;
        n = n >> 4 & m2 | (n & m2) << 4;
        n = n >> 2 & m3 | (n & m3) << 2;
        n = n >> 1 & m4 | (n & m4) << 1; 
        return n;
    }
};