class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int LOG = 17;

    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> graph;

    void dfs(int node, int parent) {
        up[0][node] = parent;

        for (int nextNode : graph[node]) {
            if (nextNode == parent) continue;

            depth[nextNode] = depth[node] + 1;
            dfs(nextNode, node);
        }
    }

    int getLCA(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        for (int bit = LOG - 1; bit >= 0; bit--) {
            if (up[bit][a] != -1 &&
                depth[up[bit][a]] >= depth[b]) {
                a = up[bit][a];
            }
        }

        if (a == b) return a;

        for (int bit = LOG - 1; bit >= 0; bit--) {
            if (up[bit][a] != -1 &&
                up[bit][a] != up[bit][b]) {
                a = up[bit][a];
                b = up[bit][b];
            }
        }

        return up[0][a];
    }

    long long modPow(long long base, long long power) {
        long long result = 1;

        while (power) {
            if (power & 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            power >>= 1;
        }

        return result;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        graph.assign(n + 1, {});
        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1, -1));

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(1, -1);

        for (int bit = 1; bit < LOG; bit++) {
            for (int node = 1; node <= n; node++) {
                if (up[bit - 1][node] != -1) {
                    up[bit][node] =
                        up[bit - 1][up[bit - 1][node]];
                }
            }
        }

        vector<int> answer;

        for (auto &query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);

            int distance =
                depth[u] + depth[v] - 2 * depth[lca];

            answer.push_back(modPow(2, distance - 1));
        }

        return answer;
    }
};