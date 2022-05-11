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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL )
            return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        int c=0;
        while(c!=n)
        {
            fast=fast->next;
            c++;
        } 
         if(fast->next==NULL)
        {
            dummy=dummy->next;
        }
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
            slow->next=slow->next->next;
        return dummy->next;
    }
};