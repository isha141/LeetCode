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
    ListNode* oddEvenList(ListNode* head) {
          if(head==NULL) 
                return head;
          ListNode *dummy=new ListNode(0);
          ListNode *even=dummy;
          ListNode *dummyO=new ListNode(0);
          ListNode *odd=dummyO;
        int count=1;
          while(head!=NULL){
              if(count%2){
                  odd->next=head;
                   odd=odd->next;
              }
              else{
                  even->next=head;
                  even=even->next;
              }
              head=head->next;
              count+=1;
          } 
          even->next=NULL;
          odd->next=NULL;
          odd->next=dummy->next;
          return dummyO->next;
    }
};