class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph,
             vector<int>& path, vector<vector<int>>& ans) {
        
        int target = graph.size() - 1;

        if (node == target) {
            ans.push_back(path);
            return;
        }

        for (int next : graph[node]) {
            path.push_back(next);
            dfs(next, graph, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        path.push_back(0); 
        dfs(0, graph, path, ans);

        return ans;
    }
};