class Solution {
public:
    void dfs(TreeNode* root, int depth, vector<int>& res) {
        if (!root) return;
        
        if (depth == res.size()) {
            res.push_back(root->val);
        } else {
            res[depth] = max(res[depth], root->val);
        }
        
        dfs(root->left, depth + 1, res);
        dfs(root->right, depth + 1, res);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};