class Solution {
private:
    int cntSubarrays(vector<int> &arr, int sum){
        int subarrSum = 0;
        int cnt = 1;

        for(int x: arr){
            if(subarrSum + x <= sum){
                subarrSum += x;
            }
            else{
                cnt++;
                subarrSum = x;
            }
        }

        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) /2;
            if(cntSubarrays(nums, mid) <= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};