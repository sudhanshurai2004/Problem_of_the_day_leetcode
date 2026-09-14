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
    ListNode* deleteDuplicates(ListNode* head) {
if(!head||!head->next)return head;
        int val=head->val;
        ListNode* temp=head;
        temp=temp->next;
        int cnt=1;
        ListNode* dummy=new ListNode(0);
        ListNode* t1=dummy;

        while(temp){
            if(temp->val==val)cnt++;
            else{
                if(cnt==1){
ListNode* x=new ListNode(val);
t1->next=x;
t1=t1->next;
                }
                cnt=1;
                val=temp->val;
            }
            temp=temp->next;
        }
        if(cnt==1){
            ListNode* x=new ListNode(val);
t1->next=x;
        }
        return dummy->next;

    }
};