class Solution {
public:
    int maxDepth = -1;
    int ans = 0;

    void dfs(TreeNode* root, int depth) {
        if (!root) return;
        
        if (depth > maxDepth) {
            maxDepth = depth;
            ans = root->val;
        }
        
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};