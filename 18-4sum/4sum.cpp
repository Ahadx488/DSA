class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         for(int k = j + 1 ; k < n; k++){
        //             for(int l = k + 1; l < n; l++){
        //                 if(nums[i] + nums[j] + nums[k] + nums[l] == target){
        //                     vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
        //                     sort(temp.begin(), temp.end());
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin() , st.end());
        // return ans;


        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         unordered_set<int> st1;
        //         for(int k = j + 1; k < n; k++){
        //             long long  x = (long long)nums[i] + nums[j] + nums[k];
        //             long long  need = (long long)target - x;
        //             if(st1.find(need) != st1.end()){
        //                 vector<int> temp{nums[i], nums[j], nums[k], (int)need};
        //                 sort(temp.begin() , temp.end());
        //                 st.insert(temp);
        //             }
        //             st1.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;
                long long x = (long long)nums[i] + nums[j];
                while(k < l){
                    if(x + nums[k] + nums[l] == target){
                        vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if(x + nums[l] + nums[k] > target) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};