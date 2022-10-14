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
    private:
    ListNode *solve(ListNode* head)
    {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
         ListNode* slow=head;
        ListNode* fast=head;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        } 
        // cout<<slow->val<<" ";
        slow->val=slow->next->val;
        slow->next=slow->next->next;
        return dummy->next;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
            return head; 
        if(head->next==NULL)
            return NULL;
        if( head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        return solve(head);
    }
};