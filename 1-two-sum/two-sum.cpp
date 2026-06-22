class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        mpp[nums[0]] = 0;
        for(int i = 1; i < n; i++){
            if(mpp.find(target - nums[i]) != mpp.end()){
                return {i ,mpp[target - nums[i]]};
            }
            else{
                mpp[nums[i]] = i;
            }
        }
        return {-1 , -1};

    }
};