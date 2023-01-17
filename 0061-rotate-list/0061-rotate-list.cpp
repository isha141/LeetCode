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
         if(head==NULL || k==0) return head;
         ListNode * p=head; 
        int c=1;
         while(p->next!=NULL) {
             p=p->next; 
             c++;
         }
         p->next=head; 
         k%=c;
        int i=0; 
        ListNode *temp=head; 
        ListNode *prev=head;
        while(i<c-k){
            i++; 
            prev=temp;
            temp=temp->next;
        }
        ListNode * ans=temp;
        prev->next=NULL;
        return ans;   
    }
};