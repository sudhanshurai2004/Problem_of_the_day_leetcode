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
    int dfs(TreeNode* root, int p, int gp) {
        if (!root) return 0;
        int sum = (gp != -1 && gp % 2 == 0) ? root->val : 0;
        return sum + dfs(root->left, root->val, p) + dfs(root->right, root->val, p);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, -1, -1);
    }
};