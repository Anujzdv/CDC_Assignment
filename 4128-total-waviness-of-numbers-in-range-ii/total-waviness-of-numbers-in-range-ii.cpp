class Solution {
    using ll = long long;

    string num;
    pair<ll, ll> memo[20][2][2][11][11][4];
    bool seen[20][2][2][11][11][4];

    pair<ll, ll> digitDP(int idx, bool tight, bool started,
                         int a, int b, int len) {

        if (idx == num.size()) return {1, 0};

        if (seen[idx][tight][started][a][b][len])
            return memo[idx][tight][started][a][b][len];

        seen[idx][tight][started][a][b][len] = true;

        ll ways = 0, waviness = 0;
        int limit = tight ? num[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool nt = tight && (d == limit);

            if (!started && d == 0) {
                auto [cnt, sum] =
                    digitDP(idx + 1, nt, false, 10, 10, 0);

                ways += cnt;
                waviness += sum;
                continue;
            }

            int add = 0;

            if (len >= 2) {
                add = ((b > a && b > d) ||
                       (b < a && b < d));
            }

            int na = (len == 0 ? 10 : b);
            int nb = d;

            auto [cnt, sum] =
                digitDP(idx + 1, nt, true,
                        na, nb, min(3, len + 1));

            ways += cnt;
            waviness += sum + 1LL * add * cnt;
        }

        return memo[idx][tight][started][a][b][len] = {ways, waviness};
    }

    ll solve(ll x) {
        if (x < 0) return 0;

        num = to_string(x);
        memset(seen, 0, sizeof(seen));

        return digitDP(0, true, false, 10, 10, 0).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};