class Solution {
public:
    int dp[16][1 << 15];

    int solve(int pos, int mask, int n) {
        if (pos > n) return 1;

        if (dp[pos][mask] != -1)
            return dp[pos][mask];

        int ans = 0;

        for (int num = 1; num <= n; num++) {
            if (!(mask & (1 << (num - 1))) &&
                (num % pos == 0 || pos % num == 0)) {

                ans += solve(pos + 1,
                             mask | (1 << (num - 1)),
                             n);
            }
        }

        return dp[pos][mask] = ans;
    }

    int countArrangement(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, n);
    }
};