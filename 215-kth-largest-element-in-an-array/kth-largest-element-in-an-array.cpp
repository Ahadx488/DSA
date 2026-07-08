class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(nums[0]);
        int i = 1;
        int n = nums.size();

        while(i < n){
            auto it = pq.top();
            //if(pq.size() > k) pq.pop();
            pq.push(nums[i++]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};