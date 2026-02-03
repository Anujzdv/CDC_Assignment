class Solution {
public:
    void dfs(int src, vector<vector<int>>&forward, vector<vector<int>>&backward, int &ans, vector<int>&vis){
        vis[src] = 1;
        for(int nbr : forward[src]){
            if(!vis[nbr]){
                ans++;
                dfs(nbr, forward, backward, ans, vis);
            } 
        }
        for(int nbr : backward[src]){
            if(!vis[nbr]){
                dfs(nbr, forward, backward, ans, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> vis(n, 0);
        vector<vector<int>> forward(n), backward(n);
        for(int i = 0; i< connections.size(); i++){
            int a = connections[i][0], b = connections[i][1];
            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        int ans = 0;
        dfs(0, forward, backward, ans, vis);
        return ans;
    }
};