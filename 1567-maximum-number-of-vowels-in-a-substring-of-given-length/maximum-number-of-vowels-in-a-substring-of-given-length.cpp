class Solution {
public:
    bool isvowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int left = 0, cnt = 0, ans = 0;
        int n = s.size();
        for(int i = 0; i < k; i++){
            if(isvowel(s[i])){
                cnt++;
            }
        }
        ans = cnt;
        for(int j = k; j < n; j++){
            if(isvowel(s[j])) cnt++;
            if(isvowel(s[j-k])) cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};