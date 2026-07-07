class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // for(int i = 0; i < n; i++){
            
        //     if(ans.size() == 0 || ans[0] != nums[i]){
        //         int cnt = 0;
        //         for(int j = i; j < n; j++){
        //             if(nums[j] == nums[i]){
        //                 cnt++;
        //             }
        //         }
                
        //         if(cnt > n / 3) ans.push_back(nums[i]);
                
        //     }
        //     if(ans.size() == 2) break;
        // }
        // return ans;

        // unordered_map<int,int> mpp;

        // for(int x: nums){
        //     mpp[x]++;
        // }
        // for(auto it : mpp){
        //     if(it.second > n / 3) ans.push_back(it.first);
        //     if(ans.size() == 2) break;
        // }

        int cnt1 = 0, cnt2 = 0;
        int ele1 , ele2;

        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1 ){
                count1++;
            }
            if(nums[i] == ele2) count2++;
        }
        if(count1 > floor(n / 3)){
            ans.push_back(ele1);
        }
        if(count2 > floor(n / 3) ){
            ans.push_back(ele2);
        }
        

        return ans;
    }
};