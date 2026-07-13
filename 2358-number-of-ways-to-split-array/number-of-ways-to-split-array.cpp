class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long  sum = accumulate(nums.begin(), nums.end(),0LL);
        int n = nums.size();
        long long x = 0;
        //vector<int> prefix ,suffix;
        int cnt = 0;
        for(int i = 0; i < n - 1 ; i++){
            x += nums[i ];
            if(x >= (sum - x)) cnt++;
        }
    
        return cnt;
    }
};