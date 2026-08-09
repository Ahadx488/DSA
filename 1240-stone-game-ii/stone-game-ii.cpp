class Solution {
private:
    int solve(int i, int M, vector<int>& suffix, vector<vector<int>>& dp) {
        int n = suffix.size() - 1;

        if(i >= n) return 0;

        if(2 * M >= n - i)
            return suffix[i];

        if(dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for(int X = 1; X <= 2 * M; X++) {
            int nextM = max(M, X);

            int current = suffix[i] - solve(i + X, nextM, suffix, dp);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for(int i = n - 1; i >= 0; i--)
            suffix[i] = piles[i] + suffix[i + 1];

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, suffix, dp);
    }
};