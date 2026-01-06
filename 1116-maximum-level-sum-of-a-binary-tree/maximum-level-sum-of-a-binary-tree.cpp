/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int ans = 1;
        int maxSum = INT_MIN;

        while (!q.empty()) {
            int levelCount = q.size();
            int currSum = 0;

            for (int i = 0; i < levelCount; i++) {
                TreeNode* curr = q.front();
                q.pop();

                currSum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                ans = level;
            }

            level++;
        }

        return ans;
    }
};