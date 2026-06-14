class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int lt = 0, rt = n-1, ans = 0, area = 0;
        while(lt < rt){
            area = min(h[rt], h[lt])*(rt - lt);
            ans = max(ans, area);
            if(h[lt] < h[rt]){
                lt++;
            }else{
                rt--;
            }
        }
        return ans;
    }
};