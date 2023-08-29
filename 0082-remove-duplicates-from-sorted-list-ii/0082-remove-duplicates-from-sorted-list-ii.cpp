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
        ListNode *dummy=new ListNode(0);
        ListNode *prev=dummy;
        while(head!=NULL){
            bool flag=0;
            int value=head->val;
            ListNode *temp=head;
            head=head->next;
            while(head!=NULL &&  head->val==value){
                head=head->next;
                flag=1;
            }
            if(!flag){
                prev->next=temp;
                prev=temp;
            }
        }
        if(prev)
            prev->next=NULL;
        return dummy->next;
    }
};