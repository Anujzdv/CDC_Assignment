class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itr) {
        vector<vector<int>>ans;
        sort(itr.begin(), itr.end());
        ans.push_back(itr[0]);
        int n = itr.size();
        for(int i = 1; i< n; i++){
            int prvend = ans.back()[1];
            int currst = itr[i][0];
            int currend = itr[i][1];
            if(prvend >= currst){
                ans.back()[1] = max(currend, prvend);
            }else{
                ans.push_back(itr[i]);
            }
        }
        return ans;
    }
};