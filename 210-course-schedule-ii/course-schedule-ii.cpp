class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(int i = 0; i < pre.size(); i++){
            int u = pre[i][0], v = pre[i][1];
            adj[v].push_back(u);
        }
        // topological sort apply
        vector<int> endegree(n, 0);
        vector<int> ans;
        for(int i =0; i<n; i++){
            for(int x : adj[i]){
                endegree[x]++;
            }
        }
        queue<int> q;
        for(int i =0 ; i< n; i++){
            if(endegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int neig : adj[curr]){
                 endegree[neig]--;
                 if(endegree[neig] == 0){
                    q.push(neig);
                 }
            }
        }
        if(ans.size() != n){
            return {};
        }else{
             return ans;
        }
       
    }
};