class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int ans = INT_MIN;
        int i = 0 , j = 0;
        while(i < n && j < m){
            if(j < i) j = i;
            if(nums1[i] > nums2[j]){
                i++;
            }
            else if(nums1[i] <= nums2[j]){
                ans = max(ans , j-i);
                j++;
            }
        }
        return (ans != INT_MIN)? ans : 0;
    }
};