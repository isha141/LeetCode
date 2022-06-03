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
    ListNode* removeElements(ListNode* head, int val) {
         ListNode* temp=head; 
         ListNode *dummy=new ListNode(0); 
        dummy->next=head;
         ListNode* prev=dummy; 
        
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                prev->next=temp->next;
            }
            else
            {
                prev=temp;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};