/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head==NULL) return NULL; 
        if(head->next==NULL) return nullptr;
          ListNode * fast=head;
        ListNode * slow=head;
         while(slow && fast && fast->next){
              slow=slow->next;
             fast=fast->next->next;
             if(slow==fast)
                 break;
         }  
        if(fast==NULL) return nullptr;
        while(head && slow){
            if(head==slow)
                 return head;
            head=head->next;
            slow=slow->next;
        }
        return slow;
    }
};