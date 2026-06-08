class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> arr1, arr2, arr3;
        for(int i = 0; i< n; i++){
            if(nums[i] < pivot){
                arr1.push_back(nums[i]);
            }else if(nums[i] == pivot){
                arr3.push_back(nums[i]);
                }
            else{
                arr2.push_back(nums[i]);
            }
        }
        for(int x : arr3){
            arr1.push_back(x);
        }
         for(int x : arr2){
            arr1.push_back(x);
        }
        return arr1;
    }
};