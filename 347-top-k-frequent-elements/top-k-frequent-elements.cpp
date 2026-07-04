class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int x : nums){
            mpp[x]++;
        }

        vector<pair<int,int>> freq;
        for(auto it: mpp){
            freq.push_back({it.second, it.first});
        }
        sort(freq.begin(), freq.end());
        vector<int> ans;
        int m = freq.size();
        for(int i = m-1; i >= m-k ; i--){
            ans.push_back(freq[i].second);
        }
        return ans;

    }
};