class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        vector<int> chosen;

        for (auto &in : intervals) {
            int cnt = 0;
            for (int x : chosen) {
                if (x >= in[0] && x <= in[1])
                    cnt++;
            }

            int need = 2 - cnt;
            for (int x = in[1]; need > 0; x--) {
                if (find(chosen.begin(), chosen.end(), x) == chosen.end()) {
                    chosen.push_back(x);
                    need--;
                }
            }
        }

        return chosen.size();
    }
};
