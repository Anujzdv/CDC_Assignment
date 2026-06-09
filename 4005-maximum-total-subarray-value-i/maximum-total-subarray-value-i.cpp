class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
     int n = nums.size();
     sort(nums.begin(), nums.end());
     long long res = 0;
     for(int i =1; i <= k; i++){
        res += (nums[n-1] - nums[0]);
     }   
     return res;
    }
};