// bruforce solution
class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int good_triplets = 0
            int length = arr.size();
    
            for(int i = 0; i < length; ++i){
                for(int j = i + 1; j < length; ++j){
                    if(abs(arr[i] - arr[j]) < = a){
                        for( int k = j + 1; k < length; ++k){
                            if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c){
                                goodTriplets++;
                            }
                        }
                    }
                }
            }
        }
    };

//optimize with BIT + enumerate j, k

/*
struct BIT {
    static const int MAXN = 1000 + 5;
    int bit[MAXN];
    void init() {
        for (int i = 0; i < MAXN; i++) bit[i] = 0;
    }
    void upd(int a, int p) {
        for (int i = a; i < MAXN; i += i&(-i)) {
            bit[i] += p;
        }
    }
    int query(int a) {
        int res = 0;
        for (int i = a; i > 0; i -= i&(-i)) {
            res += bit[i];
        }
        return res;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        else return query(r) - query(l-1);
    }
};

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        // init
        for (int& num : arr) num += 1;
        BIT bit;
        bit.init();
        // do
        int res = 0, n = arr.size();
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (abs(arr[j] - arr[k]) > b) continue;
                int l = max(arr[j] - a, max(arr[k] - c, 1));
                int r = min(arr[j] + a, min(arr[k] + c, 1001));
                res += bit.query(l, r);
            }
            bit.upd(arr[j], 1);
        }
        return res;
    }
};
*/