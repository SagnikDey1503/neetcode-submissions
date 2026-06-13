class Solution {
    unordered_map<TreeNode*, vector<int>> dp;

    int calculate(TreeNode* root, bool isParentRobbed) {
        if (!root) return 0;

        if (dp.count(root) && dp[root][isParentRobbed] != -1)
            return dp[root][isParentRobbed];

        int rb = 0, nrb = 0;

        // Rob current node
        if (!isParentRobbed) {
            rb = root->val
               + calculate(root->left, true)
               + calculate(root->right, true);
        }

        // Don't rob current node
        nrb = calculate(root->left, false)
            + calculate(root->right, false);

        return dp[root][isParentRobbed] = max(rb, nrb);
    }

public:
    int rob(TreeNode* root) {

        function<void(TreeNode*)> init = [&](TreeNode* node) {
            if (!node) return;
            dp[node] = {-1, -1};
            init(node->left);
            init(node->right);
        };

        init(root);

        return calculate(root, false);
    }
};