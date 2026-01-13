class Solution {
public:
 double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        for (auto &sq : squares) {
            double y = sq[1];
            double len = sq[2];
            totalArea += len * len;
            low = min(low, y);
            high = max(high, y + len);
        }

        double halfArea = totalArea / 2.0;

        auto areaBelow = [&](double h) {
            double area = 0.0;
            for (auto &sq : squares) {
                double y = sq[1];
                double len = sq[2];
                if (h > y) {
                    area += min(h - y, len) * len;
                }
            }
            return area;
        };

        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;
            if (areaBelow(mid) < halfArea)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};