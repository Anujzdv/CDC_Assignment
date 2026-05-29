class Solution {
public:
    int sum(int &num){
        int sm = 0;
        while(num != 0){
            int l = num % 10;
            sm += l;
            num /= 10;
        }
        return sm;
    }
    int minElement(vector<int>& nums) {
     int mins = INT_MAX;
     for(int num : nums){
        mins = min(mins, sum(num));
     }   
     return mins;
    }
};