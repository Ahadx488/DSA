#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0;
        long long current_F = 0;
        long long n = nums.size();
        
        // Step 1: Calculate the total array sum and the initial F(0)
        for (long long i = 0; i < n; i++) {
            sum += nums[i];
            current_F += i * nums[i];
        }
        
        long long max_F = current_F;
        
        // Step 2: Use the mathematical formula to calculate F(1) through F(n-1) in O(1) time each
        for (long long i = 1; i < n; i++) {
            // nums[n - i] is the element that wraps around from the back to the front
            current_F = current_F + sum - n * nums[n - i];
            max_F = max(max_F, current_F);
        }
        
        return max_F;
    }
};