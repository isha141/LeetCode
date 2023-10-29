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
    ListNode *middle(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow!=NULL && fast!=NULL && fast->next &&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
         return slow;
    }
    ListNode *merge(ListNode *a,ListNode *mid,ListNode *right){
        ListNode *dummy=new ListNode(0);
        // dummy->next=a;
        ListNode *p=dummy;
        ListNode *b=right;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                p->next=a;
                a=a->next;
                p=p->next;
            }
            else{
                p->next=b;
                b=b->next;
                p=p->next;
            }
        }
        while(a!=NULL){
            p->next=a;
            a=a->next;
            p=p->next;
        }
        while(b!=NULL){
            p->next=b;
            p=p->next;
            b=b->next;
        }
         return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
             return head;
         ListNode *left=head;
         ListNode *mid=middle(head);
         ListNode *right=mid->next;
         mid->next=NULL;
         left=sortList(left);
         right=sortList(right);
         ListNode *root=merge(left,mid,right);
         return root;
    }
};