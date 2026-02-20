class Solution {
public:
void dfs(int node, vector<vector<int>> &adj, int &cnt,vector<int> &vis){
    vis[node] = 1;
    for(int nbr : adj[node]){
        if(!vis[nbr]){
            cnt++;
            dfs(nbr, adj, cnt, vis);
        }
    }
}

    int makeConnected(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n);
    for(int i =0; i < connections.size(); i++){
        int u = connections[i][0] , v = connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> component; // store count of node for each compoenent of graph
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            int cnt = 1;
            dfs(i, adj,cnt,vis);
            component.push_back(cnt);
        }
    }
    int totalnode = 0;
    for(int i : component){
        totalnode += i;
    }
    int totalcableNeed = totalnode - 1;
    int avlcable = connections.size();
    int ans;
    if(avlcable >= totalcableNeed){
        ans = component.size() - 1;
    }else{
        ans = -1;
    }
    return ans;
    }
};