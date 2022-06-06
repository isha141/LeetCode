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
        if(head==NULL) return head;
        ListNode*  left=NULL;
        ListNode*  tail1=NULL;
        ListNode*  tail2=NULL;
        ListNode*  right=NULL;
        while(head!=NULL){
            if(head->val<x){
                if(left==NULL){
                    left=new ListNode(head->val);
                    tail1=left;
                    left->next=tail1->next=NULL;
                }
                else{
                    tail1->next=new ListNode(head->val);
                    tail1=tail1->next;
                }
            }
            else if(head->val>=x){
                if(right==NULL){
                    right=new ListNode(head->val);
                    tail2=right;
                    right->next=tail2->next=NULL;
                }
                else{
                    tail2->next=new ListNode(head->val);
                    tail2=tail2->next;
                }
            }
            head=head->next;
        } 
        if(right && tail1)
        tail1->next=right; 
        if(tail2)
        tail2->next=NULL; 
        if(left==NULL)return right;
        return left;
    }
};