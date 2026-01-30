class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string t = "L" +dominoes+ "R";
        int i = 0;
        for(int j =1; j < t.size(); j++){
            if(t[j] == '.') continue;
            if(t[i] == t[j]){
                for(int k = i+1; k < j; k++){
                    t[k] = t[i];
                }
            }else if(t[i] == 'R' && t[j] =='L'){
                int l = i + 1,r = j -1;
                while(l < r){
                    t[l++]='R';
                    t[r--]='L';
                }
            }
            i= j;
        }
        return t.substr(1,n);
    }
};