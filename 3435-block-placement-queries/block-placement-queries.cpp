class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(idx, val, node * 2, l, mid);
        else
            update(idx, val, node * 2 + 1, mid + 1, r);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (r < ql || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(ql, qr, node * 2, l, mid),
            query(ql, qr, node * 2 + 1, mid + 1, r)
        );
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int limit = min(50000, (int)queries.size() * 3) + 5;

        set<int> obstacles = {0, limit};
        SegmentTree seg(limit + 1);

        vector<bool> result;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto it = obstacles.lower_bound(x);

                int right = *it;
                int left = *prev(it);

                obstacles.insert(x);

                seg.update(x, x - left, 1, 0, limit);
                seg.update(right, right - x, 1, 0, limit);
            } else {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                int left = *prev(it);

                int best = seg.query(0, x, 1, 0, limit);
                best = max(best, x - left);

                result.push_back(best >= sz);
            }
        }

        return result;
    }
};