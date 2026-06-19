class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = INT_MIN;
        vector<int> t(gain.size()+1);
        t[0] = 0;
        for(int i =0; i<gain.size(); i++){
            t[i+1] = t[i] + gain[i];
        }
        for(int x : t){
            ans = max(x, ans);
        }
        return ans;
    }
};