class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for(char ch : text){
            if(ch == 'b'){
                b++;
            }else if(ch == 'a'){
                a++;
            }else if(ch == 'l'){
                l++;
            }else if(ch == 'o'){
                o++;
            }else if(ch == 'n'){
                n++;
            }
        }
        l = l/2;
        o = o/2;
        int cnt = 0;
        cnt = min(a,min(b,min(l,min(o,n))));
        return cnt;
    }
};