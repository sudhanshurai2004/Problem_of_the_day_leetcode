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
int ans=0;
void f(TreeNode* root,long long cs){
if(!root)return;
cs+=root->val;

f(root->left,cs*10);
f(root->right,cs*10);

if(!root->left&&!root->right)ans+=cs;
return;
}
    int sumNumbers(TreeNode* root) {
        ans=0;
        f(root,0LL);
        return ans;
    }
};