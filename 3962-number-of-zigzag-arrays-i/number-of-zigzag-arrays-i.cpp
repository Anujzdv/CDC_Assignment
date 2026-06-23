class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m), down(m);

        for (int val = 0; val < m; val++) {
            up[val] = val;
            down[val] = m - 1 - val;
        }

        vector<long long> nextUp(m), nextDown(m);
        vector<long long> pref(m + 1);

        for (int len = 3; len <= n; len++) {

            pref[0] = 0;
            for (int i = 0; i < m; i++) {
                pref[i + 1] = (pref[i] + down[i]) % MOD;
            }

            for (int i = 0; i < m; i++) {
                nextUp[i] = pref[i];
            }

            pref[0] = 0;
            for (int i = 0; i < m; i++) {
                pref[i + 1] = (pref[i] + up[i]) % MOD;
            }

            long long totalUp = pref[m];

            for (int i = 0; i < m; i++) {
                nextDown[i] = (totalUp - pref[i + 1] + MOD) % MOD;
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};