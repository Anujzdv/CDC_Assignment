class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        int rem = coins;
        for(int el : costs){
            if(el <= rem){
                res++;
                rem -= el;
            }
        }
        return res;
    }
};