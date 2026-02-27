class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        ranges::sort(arr, {}, [](int x) {
            return pair(popcount((uint32_t) x), x);
        });
        return arr;
    }
};


/*
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        ranges::sort(arr,less<>{},[](int x){
            return std::pair(__builtin_popcount((uint32_t)x),x);
        });
        return arr;
    }
};
*/