class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> d(n+1, 0);
        for(auto &nbr : edges){
            d[nbr[0]]++;
            d[nbr[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(d[i] == n -1){
                return i;
            }
        }
        return 0;
    }
};