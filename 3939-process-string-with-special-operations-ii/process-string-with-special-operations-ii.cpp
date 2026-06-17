class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);
        long long cur = 0;
        const long long LIM = 1e18;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '*') {
                if (cur > 0) cur--;
            }
            else if (ch == '#') {
                cur = min(LIM, cur * 2);
            }
            else if (ch == '%') {
            }
            else {
                cur = min(LIM, cur + 1);
            }

            len[i] = cur;
        }

        if (k >= cur) return '.';

        long long L = cur;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                if (k == L - 1) return ch;
                L--;
            }
            else if (ch == '#') {
                long long old = len[i - 1];
                k %= old;
                L = old;
            }
            else if (ch == '%') {
                k = L - 1 - k;
            }
            else { // '*'
                L++;
            }
        }

        return '.';
    }
};