class Solution {
public:
    int getMaxHistogram(vector<int>& bars) {
        stack<int> indexStack;
        bars.push_back(0);

        int best = 0;

        for (int pos = 0; pos < bars.size(); pos++) {
            while (!indexStack.empty() && bars[indexStack.top()] > bars[pos]) {
                int heightValue = bars[indexStack.top()];
                indexStack.pop();

                int widthValue;
                if (indexStack.empty())
                    widthValue = pos;
                else
                    widthValue = pos - indexStack.top() - 1;

                best = max(best, heightValue * widthValue);
            }
            indexStack.push(pos);
        }

        bars.pop_back();
        return best;
    }

    int maximalRectangle(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        vector<int> colHeight(totalCols, 0);
        int answer = 0;

        for (int r = 0; r < totalRows; r++) {
            for (int c = 0; c < totalCols; c++) {
                if (grid[r][c] == '1')
                    colHeight[c] += 1;
                else
                    colHeight[c] = 0;
            }
            answer = max(answer, getMaxHistogram(colHeight));
        }

        return answer;
    }
};
