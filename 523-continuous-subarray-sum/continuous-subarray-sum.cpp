class Solution {
public:
    // here appproach of modulo is used
    // imp formula
    // (a - b) % k = 0 then a % k = b % k
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp; // (remainder, fist idx of rem)
        mp[0] = -1;
        int presum = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            presum += nums[i];
            if(k != 0){
                presum = presum % k; // remainder of presum 
            }
            if(mp.find(presum) != mp.end()){
                if(i - mp[presum] >= 2) {
                    return true;
                }
            }else{
                mp[presum] = i;
            }
        }
        return false;
    }
};