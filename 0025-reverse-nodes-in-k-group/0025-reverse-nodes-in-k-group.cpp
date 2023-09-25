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
        int len=0;
        ListNode *root=head;
        while(head!=NULL){
            len+=1;
            head=head->next;
        }
        ListNode *dummy=new ListNode(0);
        dummy->next=root;
         ListNode *pre=dummy;
         ListNode *nex=dummy;
         ListNode *curr=dummy;
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
            pre=curr;
            len-=k;
        }
        return dummy->next;
        
    }
};