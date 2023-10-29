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
        if(head==NULL) 
            return head;
        if(head->next==NULL && n==1)
             return NULL;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *p=dummy;
        for(int i=1;i<=n;++i){
            p=p->next;
        }
        if(p->next==head)
              return head->next;
        ListNode *temp=dummy;
        int count=0;
        while(p->next){
            p=p->next;
            temp=temp->next;
            // count+=1;
        }
         // if(temp->next && temp->next->next)
         temp->next=temp->next->next;
        return dummy->next;
    }
};