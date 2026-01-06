class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<long long, long long> left, right;
        
        for (long long x : nums) {
            right[x]++;
        }
        
        long long ans = 0;
        
        for (long long x : nums) {
            right[x]--;
            
            long long target = 2LL * x;
            ans = (ans + left[target] * right[target]) % MOD;
            
            left[x]++;
        }
        
        return (int)ans;  
    }
};