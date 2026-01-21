class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            if (num == 2) {
                ans.push_back(-1);
            } else {
                int inv = ~num;
                int lowestOne = inv & -inv;
                ans.push_back(num ^ (lowestOne >> 1));
            }
        }
        return ans;  
    }
};