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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return 0;
        ListNode * slow=head;
        ListNode * fast=head;
        do{ 
            if(slow==NULL || fast==NULL) return 0;
           slow=slow->next; 
            if(fast->next)
            fast=fast->next->next;
            else return 0;
        }while(slow!=fast);
        return slow==NULL?0:1;
    }
};