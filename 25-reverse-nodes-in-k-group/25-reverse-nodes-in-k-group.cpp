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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* curr=head;
        int c=0;
        ListNode* dummy=new ListNode();
        dummy->next=curr;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        ListNode* prev=dummy;
        ListNode* nex=dummy;
        while(c>=k)
        {
            curr=prev->next;
            nex=curr->next;
            int j=1;
            while(j<k)
            {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next; 
                j++;
            }
            c-=k;
            prev=curr;
        }
        return dummy->next;
    }
};