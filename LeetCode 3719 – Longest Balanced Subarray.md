
---

## 💡 Approach

- Since the array size is small (`n ≤ 1500`), we can use a **brute-force O(n²)** solution.
- For each starting index `i`:
  - Expand the subarray to the right (`j ≥ i`)
  - Use a hash set to track **distinct elements**
  - Maintain two counters:
    - `evenCnt` → distinct even numbers
    - `oddCnt` → distinct odd numbers
- Whenever `evenCnt == oddCnt`, update the answer.

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            int evenCnt = 0, oddCnt = 0;

            for (int j = i; j < n; j++) {
                if (seen.find(nums[j]) == seen.end()) {
                    seen.insert(nums[j]);
                    if (nums[j] % 2 == 0)
                        evenCnt++;
                    else
                        oddCnt++;
                }

                if (evenCnt == oddCnt) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
