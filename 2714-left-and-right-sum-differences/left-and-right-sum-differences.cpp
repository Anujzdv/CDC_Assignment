class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> rs(nums.size());
         vector<int> ls(nums.size());
        ls[0]=0;
        int n= nums.size();
        rs[nums.size()-1] = 0;
        for(int i =0; i< n-1; i++){
            ls[i+1] = nums[i] + ls[i];
        }
        for(int i = n-1; i >= 1; i--){
            rs[i-1] = nums[i] + rs[i];
        }
        for(int i =0; i<n; i++){
            nums[i] = abs(ls[i] - rs[i]);
        }
        return nums;
    }
};