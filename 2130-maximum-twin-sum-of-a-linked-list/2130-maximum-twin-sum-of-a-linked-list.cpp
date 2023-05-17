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
     ListNode* reverse(ListNode * head){
           ListNode* temp=head->next;
             head->next=NULL;
           while(temp!=NULL){
               ListNode *p=temp->next;
                temp->next=head; 
                 head=temp;
                  temp=p;
           }
          return head;
     }
public:
    int pairSum(ListNode* head) {
         int ans=0;
         if(head==NULL) return 0;
        ListNode* slow=head;
        ListNode* fast=head;
         while(slow && fast && fast ->next){
              slow=slow->next;
              fast=fast->next->next;
         } 
         slow= reverse(slow);
          while(slow!=NULL){
               ans=max(ans,slow->val+head->val);
               slow=slow->next;
               head=head->next;
          }
        return ans;
    }
};