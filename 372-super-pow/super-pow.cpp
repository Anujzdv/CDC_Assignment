class Solution {
public:
    int powe(int a, long long b, int mod){
        a = a % mod;
        int ans = 1;
        while(b > 0){
            if(b & 1){
                ans = (ans * a) % mod;
            }
            a = (a*a) % mod;
            b = b >> 1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
       long long ans = 1;
        for(int digit : b){
            ans = (powe(ans,10,1337) * powe(a,digit,1337))% 1337;
        }
        return ans;
    }
};