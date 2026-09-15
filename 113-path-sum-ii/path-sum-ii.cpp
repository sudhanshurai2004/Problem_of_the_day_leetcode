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
void f(TreeNode* root,int cs,int ts,vector<int>&v,vector<vector<int>>&ans){
    if(!root)return;
       v.push_back(root->val);
       cs+=root->val;
        f(root->left,cs,ts,v,ans);
        f(root->right,cs,ts,v,ans);
        if(cs==ts&&!root->left&&!root->right)ans.push_back(v);
        v.pop_back();
        
    
}
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
vector<vector<int>>ans;vector<int>v;
f(root,0,ts,v,ans);
return ans;

        
    }
};