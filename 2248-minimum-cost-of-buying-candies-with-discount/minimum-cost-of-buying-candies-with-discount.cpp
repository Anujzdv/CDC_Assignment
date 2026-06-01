class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        long long res = 0;
        if(cost.size()==2){
            return cost[0]+cost[1]; 
        }
         if(cost.size()==1){
            return cost[0]; 
        }
        for(int i = 0; i < cost.size(); i++){
            if((i+1) %3 != 0 || i== 0){
            res += cost[i];
            }
        }
        // int i = cost.size()-1;
        // int j = 0;
        // while(i >= 0 || j>= 0){
        //     res += (cost[i]+cost[j]);
        //     i = i+2;
        //     j = j+2;
        // }
        return res;
    }
};