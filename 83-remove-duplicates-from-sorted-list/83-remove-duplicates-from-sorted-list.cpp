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
        ListNode* temp=head;
        ListNode* p=head;
        while(p!=NULL)
        {
            while(p && temp->val==p->val)
                p=p->next;
            temp->next=p;
            temp=p;
           if(p) p=p->next;      
        }
        return head;
    }
};