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
    unordered_map<int, int> freqMap;
    int maxFreq = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        int totalSum = root->val + leftSum + rightSum;
        
        freqMap[totalSum]++;
        maxFreq = max(maxFreq, freqMap[totalSum]);
        
        return totalSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        
        vector<int> result;
        for (auto& it : freqMap) {
            if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};