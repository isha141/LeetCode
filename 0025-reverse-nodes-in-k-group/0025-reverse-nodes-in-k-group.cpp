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
    int solve(ListNode *head){
        int count=0;
        while(head!=NULL){
            count+=1;
            head=head->next;
        }
        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
          if(head==NULL)
                return head;
          int len=solve(head);
          // cout<<len<<"-->"<<endl;
          ListNode *dummy=new ListNode(0);
          dummy->next=head;
          ListNode *nex=dummy;
          ListNode *curr=dummy;
          ListNode *pre=dummy;
          while(len>=k){
              curr=pre->next;
              nex=curr->next;
              int temp=1;
              while(temp<k){
                   curr->next=nex->next;
                   nex->next=pre->next;
                   pre->next=nex;
                   nex=curr->next;
                   temp+=1;
              }
              len-=k;
              pre=curr;
          }
          return dummy->next;
    }
};