class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        
        for(int x: nums){
            mpp[x]++;
        }

        for(auto it: mpp){
            if(it.second > floor(n / 2)) return it.first;
        }
        return -1;

    }
};