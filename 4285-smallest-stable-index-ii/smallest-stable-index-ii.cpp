class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nextMin(n);

        nextMin[n-1] = nums[n-1];

        for(int i = n-2; i >=0; i--){
            nextMin[i] = min(nextMin[i+1] , nums[i]);
        }

        int prevMax = nums[0];

        for(int i = 0; i < n; i++){
            prevMax = max(prevMax , nums[i]);
            int score = prevMax - nextMin[i];
            if(score <= k) return i;
        }
        return -1;
    }
};