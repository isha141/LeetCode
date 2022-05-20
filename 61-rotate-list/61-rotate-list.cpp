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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head; 
        int len=1; 
        if(head==NULL || head->next==NULL)
            return head;
        while(curr->next!=NULL)
        { 
            len++;
            curr=curr->next;
        }
        k=k%len;
        curr->next=head;
        k=len-k;
        int j=1;
        while(j!=k)
        {
            j++;
            head=head->next;
        }
        curr=head->next;
        head->next=NULL;
        return curr;
    }
};