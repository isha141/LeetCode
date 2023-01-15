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
         if(head==NULL || k==1)
             return head; 
        ListNode* dummy=new ListNode(0);
        dummy->next=head; 
        int cnt=0;
        while(head!=NULL){
            head=head->next;
            cnt++;
        }  
        // cout<<cnt<<endl;
        ListNode* curr=dummy; 
        ListNode* nex=dummy;
        ListNode* pre=dummy;
        while(cnt>=k){
             curr=pre->next;
             nex=curr->next;
              int temp=1;
            while(temp<k){
                curr->next=nex->next; 
                nex->next=pre->next;
                pre->next=nex; 
                nex=curr->next;
                temp++;
            }
            cnt-=k;
            pre=curr;
        }
        return dummy->next;
        
        
    }
};