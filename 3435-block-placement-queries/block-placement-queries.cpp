class SegTree {
public:
    int n;
    vector<int> seg;

    SegTree(int n) : n(n) {
        seg.assign(4 * n + 5, 0);
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (qr < l || r < ql) return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) >> 1;

        return max(
            query(ql, qr, 2 * node, l, mid),
            query(ql, qr, 2 * node + 1, mid + 1, r)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 1, 0, n);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int MX = 50000;

        set<int> obs;
        obs.insert(0);
        obs.insert(MX);

        vector<int> added;

        for (auto &q : queries) {
            if (q[0] == 1) {
                obs.insert(q[1]);
                added.push_back(q[1]);
            }
        }

        SegTree st(MX);

        auto it = obs.begin();
        auto prv = it;
        ++it;

        while (it != obs.end()) {
            st.update(*it, *it - *prv);
            prv = it;
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            auto &q = queries[i];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                int best = st.query(0, x);

                auto it = obs.upper_bound(x);
                --it;

                best = max(best, x - *it);

                ans.push_back(best >= sz);
            }
            else {

                int x = q[1];

                auto cur = obs.find(x);

                auto L = prev(cur);
                auto R = next(cur);

                st.update(x, 0);
                st.update(*R, *R - *L);

                obs.erase(cur);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};