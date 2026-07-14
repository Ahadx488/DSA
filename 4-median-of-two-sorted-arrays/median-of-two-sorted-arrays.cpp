class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j])
                ans.push_back(nums1[i++]);
            
            else
                ans.push_back(nums2[j++]); 
        }

        while(i < n1){
            ans.push_back(nums1[i++]);
        }

        while(j < n2){
            ans.push_back(nums2[j++]);
        }
        int n = n1 + n2;
        return (n % 2 != 0) ? ans[n / 2] : ((double)ans[n / 2] + ans[n / 2 -1]) /2.0;
    }
};