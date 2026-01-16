class Solution {
public:
    int myAtoi(string s) {
        int i = 0,base = 0;
        int flag = 1; 
        while(s[i] == ' ')i++;
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '-')flag = -1;
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9'){
            if(base > INT_MAX/10 || (base == INT_MAX/10 && s[i] -'0' > 7)){
                if(flag == 1)return INT_MAX;
                return INT_MIN;
            }
            base *= 10;
            base += (s[i] - '0');
            i++;
        }
        return base*flag;
    }
};