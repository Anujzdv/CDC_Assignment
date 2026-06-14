class Solution {
public:
    int trap(vector<int>& h ) {
        int n = h.size();
        if(n==0) return 0;
        int lt = 0, rt = n-1, ans = 0, ltmx = h[lt] , rtmx = h[rt];
        while(lt  < rt){
            if(ltmx < rtmx){
                lt++;
                ltmx = max(ltmx, h[lt]);
                ans += ltmx - h[lt];
            }else{
                rt--;
                rtmx = max(rtmx, h[rt]);
                ans += rtmx - h[rt];
            }
        }
        return ans;
    }
};