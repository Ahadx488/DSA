class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);

        for(int i = 0; i < n; i++){
            
            if(i > 0) leftSum[i] =leftSum[i - 1] + nums[i-1];
            rightSum[i] = accumulate(nums.begin() + i + 1, nums.end(), 0);

        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }

        return ans;
    }
};