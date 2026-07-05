class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int,int> mpp;
        
        // for(int x: nums){
        //     mpp[x]++;
        //     if(mpp[x] > n /2) return x;
        // }

        // // for(auto it: mpp){
        // //     if(it.second > floor(n / 2)) return it.first;
        // // }
        // return -1;

        int element ;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == element){
                count++;
            }
            if(nums[i] != element){
                if(count == 0){
                    element = nums[i];
                    count++;
                    continue;
                }
                count--;
            }
        }
        int cntMajEle = 0;
        for(int i = 0; i < n ;i++){
            if(nums[i] == element) cntMajEle++;
        }
        return (cntMajEle > n / 2)? element : -1;

    }
};