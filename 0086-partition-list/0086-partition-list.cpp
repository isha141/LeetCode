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
    ListNode* partition(ListNode* head, int x) {
        ListNode *fdummy=new ListNode(0);
        ListNode *sdummy=new ListNode(0);
        ListNode *first=fdummy;
        ListNode *second=sdummy;
        while(head!=NULL){
            if(head->val<x){
                first->next=head;
                first=first->next;
            }
            else{
                second->next=head;
                second=second->next;
            }
            head=head->next;
        }
        first->next=sdummy->next;
        second->next=NULL;
        return fdummy->next;
    }
};