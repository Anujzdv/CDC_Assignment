class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res ="";
        for(int i =0; i< words.size(); i++){
            int cnt  = 0;
            for(int j = 0; j< words[i].size(); j++){
                char ch = words[i][j];
                cnt += weights[ch - 'a'];
            }
            int mod = cnt % 26;
            char mapp = 'z' - mod;
            res += mapp;
        }
        return res;
    }
};