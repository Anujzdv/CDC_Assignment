class Solution {
public:
    bool helper(vector<int>& arr, int sum, int n){
        bool t[n+1][sum + 1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j< sum +1; j++){
                if(i == 0){
                    t[i][j] = false;
                } if(j == 0){
                    t[i][j] = true;
                }
            }
        }
      for(int i = 1; i< n+1; i++){
          for(int j = 1; j < sum +1 ; j++){
              if(arr[i-1] <= j){
                  t[i][j] = (t[i-1][j - arr[i-1]] || t[i-1][j]);
              }else{
                  t[i][j] = t[i-1][j];
              }
          
      }
      }
      return t[n][sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return helper(arr, sum, n);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if(sum % 2 != 0){
            return false;
        }else{
            return isSubsetSum(nums, sum/2);
        }
    }
};