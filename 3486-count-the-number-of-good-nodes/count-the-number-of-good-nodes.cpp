class Solution {
public:
    int res = 0;
    vector<vector<int>> adj;
    
    int dfs(int node, int parent) {
        int subtreeSize = 1;
        int commonSize = -1; 
        bool isGood = true;
        
        for (int child : adj[node]) {
            if (child == parent) continue;
            int childSize = dfs(child, node);
            subtreeSize += childSize;
            
            if (commonSize == -1) {
                commonSize = childSize;
            } else if (commonSize != childSize) {
                isGood = false;
            }
        }
        
        if (isGood) res++;
        return subtreeSize;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adj.assign(n, {});
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1);
        return res;
    }
};
