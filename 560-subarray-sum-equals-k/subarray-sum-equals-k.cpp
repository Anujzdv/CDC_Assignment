class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int cnt = 0;
        int n = nums.size();
        vector<int> presum (n,0);
        presum[0] = nums[0];
        for(int i = 1; i < n; i++){
            presum[i] = presum[i - 1] + nums[i];
        }
        for(int j = 0; j<n; j++){
            if(presum[j] == k){
                cnt++;
            }
            int val = presum[j] - k;
            if(mp.find(val)!=mp.end()){
                cnt += mp[val];
            }
            mp[presum[j]]++;
            
        }
        return cnt;

    }
};