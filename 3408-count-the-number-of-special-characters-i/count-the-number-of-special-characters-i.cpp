class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> s,t;
        for(char c : word){
            s.insert(c);
        }
        int n = s.size();
        word = "";

        for(char c : s){
            word += tolower(c);
        }
        for(char c : word){
            t.insert(c);
        }
        int m = t.size();
        return n-m;

    }
};