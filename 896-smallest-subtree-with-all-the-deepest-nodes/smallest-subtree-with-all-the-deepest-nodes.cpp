class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (root == nullptr)
            return make_pair(0, nullptr);

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.first > right.first)
            return make_pair(left.first + 1, left.second);
        else if (right.first > left.first)
            return make_pair(right.first + 1, right.second);
        else
            return make_pair(left.first + 1, root);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
