class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1;j < n ; j++ ){
                ans = max(ans, (nums[i] - 1) * (nums[j ] - 1));
            }
        }

        return ans;
    }
};