/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode* f(vector<int>&v,int si,int ei){
    if(ei<si)return NULL;
    if(si==ei){
        TreeNode* ans=new TreeNode(v[si]);
        return ans;
    }
    int mid=(si+ei)/2;
        TreeNode* ans=new TreeNode(v[mid]);
        ans->left=f(v,si,mid-1);
        ans->right=f(v,mid+1,ei);
        return ans;
}
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v;
        if(!head)return NULL;
        ListNode* temp=head;
        while(temp){
v.push_back(temp->val);
temp=temp->next;
        }
        TreeNode* ans=f(v,0,v.size()-1);
        return ans;
    }
};