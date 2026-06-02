class Solution {
public:
    int calc(vector<int>& s1, vector<int>& d1,
             vector<int>& s2, vector<int>& d2) {

        int firstEnd = INT_MAX;
        for (int i = 0; i < s1.size(); i++) {
            firstEnd = min(firstEnd, s1[i] + d1[i]);
        }

        int res = INT_MAX;
        for (int i = 0; i < s2.size(); i++) {
            res = min(res, max(s2[i], firstEnd) + d2[i]);
        }

        return res;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        return min(
            calc(landStartTime, landDuration,
                 waterStartTime, waterDuration),
            calc(waterStartTime, waterDuration,
                 landStartTime, landDuration)
        );
    }
};