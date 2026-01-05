class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;

        for (auto &row : matrix) {
            for (int value : row) {
                if (value < 0) negativeCount++;
                totalSum += abs(value);
                minAbsValue = min(minAbsValue, abs(value));
            }
        }

        if (negativeCount % 2 == 1) {
            totalSum -= 2 * minAbsValue;
        }

        return totalSum;
    }
};