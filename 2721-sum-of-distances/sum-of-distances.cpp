class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto &it : mp) {
            auto &v = it.second;
            int m = v.size();

            vector<long long> prefix(m);
            prefix[0] = v[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i-1] + v[i];
            }

            for (int j = 0; j < m; j++) {
                long long left = (long long)v[j] * j - (j > 0 ? prefix[j-1] : 0);
                long long right = (prefix[m-1] - prefix[j]) - (long long)(m - j - 1) * v[j];
                ans[v[j]] = left + right;
            }
        }

        return ans;
    }
};