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
          if(head==NULL)
                return head;
          ListNode *ans=head;
           ListNode * res=head;
        head=head->next;
          while(head!=NULL){
              while(head && ans->val==head->val){
                  head=head->next;
              }
              ans->next=head;
              ans=head;
          }
          return res;
    }
};