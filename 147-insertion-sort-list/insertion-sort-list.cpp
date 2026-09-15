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
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* ans=new ListNode(head->val);
        ListNode* t=head->next;
        while(t){
            if(t->val<=ans->val){
                ListNode* x=new ListNode(ans->val);
                x->next=ans->next;
                ans->next=x;
                ans->val=t->val;
            }
            else{
ListNode* t1=ans;
ListNode* prev=ans;
while(t1){
    if(t1->val>=t->val){
        ListNode* x=new ListNode(t1->val);
                x->next=t1->next;
                t1->next=x;
                t1->val=t->val;
                break;
    }
    prev=t1;
    t1=t1->next;

}
if(!t1){
   prev->next =new ListNode(t->val);
}
            }
            
t=t->next;
        }
        return ans;

    }
};