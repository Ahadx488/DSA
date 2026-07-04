class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int x : nums){
            mpp[x]++;
        }

        // vector<pair<int,int>> freq;
        // for(auto it: mpp){
        //     freq.push_back({it.second, it.first});
        // }
        // sort(freq.begin(), freq.end());
        // vector<int> ans;
        // int m = freq.size();
        // for(int i = m-1; i >= m-k ; i--){
        //     ans.push_back(freq[i].second);
        // }
        // return ans;


        // ====== MIN_HEAP Soln ========
        
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // for(auto it: mpp){
        //     pq.push({it.second, it.first});
        //     if (pq.size() > k) pq.pop();
        // }
        // vector<int>ans;
        // for(int i = 0; i < k; i++){
        //     auto p = pq.top();
        //     pq.pop();
        //     ans.push_back(p.second);
        // }
        // return ans;


        // ======= BUCKET SORT ========

        vector<vector<int>> bucket(n+1);
        for(auto it: mpp){
            bucket[it.second].push_back(it.first);
        }
         vector<int>ans;
        for(int i = n; i >= 0;i--){
            if(bucket[i].size() == 0) continue;
            
            for(auto it: bucket[i]){
                if(ans.size() < k) ans.push_back(it);
            }
            if(ans.size() >= k) break;
        }
        return ans;

    }
};