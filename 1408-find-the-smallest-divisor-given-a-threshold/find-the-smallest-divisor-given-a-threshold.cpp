class Solution {
private:
    int findSum (vector<int> &nums, int d){
        int sum = 0;

        for(int x: nums){
            sum += (x + d -1)/ d;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;

            int divSum = findSum(nums, mid);

            if(divSum > threshold){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};