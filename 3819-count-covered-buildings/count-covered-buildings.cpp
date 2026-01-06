class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minY(n+1, INT_MAX), maxY(n+1, INT_MIN);
        vector<int> minX(n+1, INT_MAX), maxX(n+1, INT_MIN);
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            minY[x] = min(minY[x], y);
            maxY[x] = max(maxY[x], y);
            minX[y] = min(minX[y], x);
            maxX[y] = max(maxX[y], x);
        }
        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            if (minY[x] < y && y < maxY[x] && minX[y] < x && x < maxX[y]) {
                ans++;
            }
        }
        return ans;
    }
};