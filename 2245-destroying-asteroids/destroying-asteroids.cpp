class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(begin(nums),end(nums));
    

        long long m = mass;
        if(nums[0]>m)
            return false;
        for(auto& it:nums){
            if(it<=m){
                m+=it;
            }
            else
                return false;
        }
        return true;
    }
};