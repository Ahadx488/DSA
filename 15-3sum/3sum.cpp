class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        // set<vector<int>> st;
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         for(int k = j + 1; k < n; k++){
        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin() , temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin() , st.end());
        // return ans;


        // Better approach -> o(n2 * log(M)); M = no.of unique tuples


        // vector<vector<int>> ans;
        // set<vector<int>> tupl;
        // for(int i = 0; i < n; i++){
        //     unordered_set<int> st;
        //     for(int j = i +1; j < n; j++){
                
        //         int x = -1 * (nums[i] + nums[j]);
        //         if(st.find(x) != st.end()){
        //             vector<int> temp {nums[i] , nums[j] , x};
        //             sort(temp.begin() , temp.end());
        //             tupl.insert(temp);
        //         }
        //         else{
        //             st.insert(nums[j]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans (tupl.begin() , tupl.end());
        // return ans;



        // optimal Approach: O(nlogn) + O(n2),

        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i -1]) continue;
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum  = nums[i] + nums[j] + nums[k];
                if( sum == 0){
                    vector<int> temp {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
                else if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }
                
            }
        }
        return ans;
    }
};