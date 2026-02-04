class Solution {
public:
    bool bfs(int src,vector<vector<int>> &adj, int n){
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                for(int neigh : adj[curr]){
                    if(!vis[neigh]){
                       vis[neigh] = 1;
                       q.push(neigh);
                    }
                }
            }
        }
        for(int el : vis){
            if(el != 1){
                return false;
            }
        }
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for(int i =0; i< n; i++){
            for(int j =0; j < rooms[i].size(); j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        return bfs(0,adj,n);
    }
};