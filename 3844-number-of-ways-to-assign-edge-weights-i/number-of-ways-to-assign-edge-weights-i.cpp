class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(1);

        vector<int> vis(n + 1);
        vis[1] = 1;

        int depth = -1;

        while (!q.empty()) {
            int sz = q.size();
            depth++;

            while (sz--) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (vis[v]) continue;

                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return modPow(2, depth - 1);
    }
};
