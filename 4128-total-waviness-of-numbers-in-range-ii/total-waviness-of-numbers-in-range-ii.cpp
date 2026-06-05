class Solution {
public:
    struct Node {
        long long cnt;
        long long wave;
    };

    string s;
    Node dp[17][11][11][2][2];
    bool vis[17][11][11][2][2];

    Node solveDP(int pos,
                 int prev2,
                 int prev1,
                 bool tight,
                 bool started) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][started][0])
            return dp[pos][prev2][prev1][started][0];

        int limit = tight ? s[pos] - '0' : 9;

        Node res = {0, 0};

        for (int dig = 0; dig <= limit; dig++) {

            bool ntight = tight && (dig == limit);

            if (!started && dig == 0) {

                Node nxt =
                    solveDP(pos + 1, 10, 10, ntight, false);

                res.cnt += nxt.cnt;
                res.wave += nxt.wave;
            }
            else {

                Node nxt;

                if (!started) {
                    nxt = solveDP(pos + 1,
                                  10,
                                  dig,
                                  ntight,
                                  true);

                    res.cnt += nxt.cnt;
                    res.wave += nxt.wave;
                }
                else {

                    int add = 0;

                    if (prev2 != 10) {
                        if ((prev2 < prev1 && prev1 > dig) ||
                            (prev2 > prev1 && prev1 < dig))
                            add = 1;
                    }

                    nxt = solveDP(pos + 1,
                                  prev1,
                                  dig,
                                  ntight,
                                  true);

                    res.cnt += nxt.cnt;
                    res.wave += nxt.wave + 1LL * add * nxt.cnt;
                }
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][started][0] = true;
            dp[pos][prev2][prev1][started][0] = res;
        }

        return res;
    }

    long long F(long long x) {

        if (x <= 0) return 0;

        memset(vis, 0, sizeof(vis));

        s = to_string(x);

        return solveDP(0, 10, 10, true, false).wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return F(num2) - F(num1 - 1);
    }
};