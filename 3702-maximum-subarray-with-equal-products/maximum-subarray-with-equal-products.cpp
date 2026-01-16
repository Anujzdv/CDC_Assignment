class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long currentLcm = 1;
            int currentGcd = 0;

            for (int j = i; j < n; j++) {
                // Prevent overflow
                if (product > LLONG_MAX / nums[j]) break;

                product *= nums[j];
                currentGcd = gcd(currentGcd, nums[j]);
                currentLcm = lcm(currentLcm, nums[j]);

                // Prune impossible cases
                if (product > currentGcd * currentLcm) break;

                if (product == currentGcd * currentLcm) {
                    answer = max(answer, j - i + 1);
                }
            }
        }
        return answer; 
    }
};