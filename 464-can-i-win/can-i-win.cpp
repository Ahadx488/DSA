class Solution {
private:
    unordered_map<int, bool> dp;

    bool solve(int mask, int total, int maxNum) {
        if(dp.count(mask))
            return dp[mask];

        for(int i = 1; i <= maxNum; i++) {

            if(mask & (1 << (i - 1)))
                continue;

            if(i >= total)
                return dp[mask] = true;

            if(!solve(mask | (1 << (i - 1)), total - i, maxNum))
                return dp[mask] = true;
        }

        return dp[mask] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if(desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if(sum < desiredTotal)
            return false;

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};