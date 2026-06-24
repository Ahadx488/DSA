class Solution {
public:
    static const int MOD = 1000000007;

    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp) {
            if (exp & 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<ll> multiplyMatVec(Matrix &A, vector<ll> &v) {
        int n = A.size();
        vector<ll> res(n, 0);

        for (int i = 0; i < n; i++) {
            ll cur = 0;

            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 2) {
            return (int)(1LL * m * (m - 1) % MOD);
        }

        int S = 2 * m;

        Matrix T(S, vector<ll>(S, 0));

        for (int x = 0; x < m; x++) {

            for (int y = 0; y < x; y++) {
                T[x][m + y] = 1;
            }

            for (int y = x + 1; y < m; y++) {
                T[m + x][y] = 1;
            }
        }

        vector<ll> state(S, 0);

        for (int b = 0; b < m; b++) {
            state[b] = b;
            state[m + b] = m - 1 - b;
        }

        Matrix P = power(T, n - 2);

        vector<ll> finalState =
            multiplyMatVec(P, state);

        ll ans = 0;

        for (ll x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};