class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < nums[minIdx])
                minIdx = i;

            if(nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // Remove both from front
        int front = max(minIdx, maxIdx) + 1;

        // Remove both from back
        int back = n - min(minIdx, maxIdx);

        // Remove one from front, other from back
        int mixed = minIdx + 1 + n - maxIdx;

        // The above assumes minIdx < maxIdx.
        // If maxIdx < minIdx, calculate the other orientation.
        mixed = min(mixed,
                    maxIdx + 1 + n - minIdx);

        return min({front, back, mixed});
    }
};