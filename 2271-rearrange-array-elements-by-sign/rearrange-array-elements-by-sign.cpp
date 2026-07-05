class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pInd = 0;
        int nInd = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0) {
                ans[pInd] = nums[i];
                pInd = pInd + 2;
            }
            else{
                ans[nInd] = nums[i];
                nInd = nInd + 2;
            }
        }
        return ans;
    }
};