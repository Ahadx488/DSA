class Solution {
private:
    int findDays(vector<int> & nums, int limit, int days){
        int sum = 0;
        int cntDays = 1;
        for(int x: nums){
            sum += x;
            if(sum > limit){
                sum = x;
                cntDays++;
            }
        }
        return cntDays;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin() , weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;

            int totalDays = findDays(weights, mid, days);
            if(totalDays  <= days){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }

        } 
        return ans;
    }
};