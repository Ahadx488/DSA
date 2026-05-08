class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    mp[d].push_back(i);

                    if (d != x / d)
                        mp[x / d].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            // adjacent
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            // teleport
            if (isPrime(nums[i])) {
                int p = nums[i];

                for (int nxt : mp[p]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[i] + 1;
                        q.push(nxt);
                    }
                }

                mp[p].clear();
            }
        }

        return -1;
    }
};