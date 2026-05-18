class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);

        queue<pair<int,int>> q;

        q.push({0, 0});
        vis[0] = 1;

        while(!q.empty()) {

            auto [idx, steps] = q.front();
            q.pop();

            if(idx == n - 1)
                return steps;

            // i - 1
            if(idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

            // i + 1
            if(idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            // same value jumps
            for(int nxt : mp[arr[idx]]) {

                if(!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push({nxt, steps + 1});
                }
            }

            mp[arr[idx]].clear();
        }

        return -1;
    }
};