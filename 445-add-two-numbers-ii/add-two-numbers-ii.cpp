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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>v1,v2;
        ListNode*t1=l1;
        while(t1){
            v1.push_back(t1->val);
            t1=t1->next;
        }
        t1=l2;
        while(t1){
            v2.push_back(t1->val);
            t1=t1->next;
        }
        reverse(v1.begin(),v1.end());reverse(v2.begin(),v2.end());
        if(v1.size()<v2.size())swap(v1,v2);
        int cr=0;
        for(int i=0;i<v1.size();i++){
            int val=v1[i];
            val+=cr;
            if(i<v2.size())val+=v2[i];
            cr=val/10;
            v1[i]=val%10;
        }
        if(cr>0)v1.push_back(cr);
ListNode* dummy=new ListNode(0);
ListNode* t=dummy;
for(int i=v1.size()-1;i>=0;i--){
    ListNode* x=new ListNode(v1[i]);
    t->next=x;
    t=t->next;
}return dummy->next;
    }
};