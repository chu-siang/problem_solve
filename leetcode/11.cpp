class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        for(int i  = 0 , j = height.size() -1 ; i < j; ){ //outer loop  
                //goal : find the maximum (j - i) * (min (height[i], height[j]);
                mx = max(mx, (j-i)*min(height[i],height[j]));
                if(height[i] > height[j])j--;
                else i++;
        }
        return mx;
    }
};