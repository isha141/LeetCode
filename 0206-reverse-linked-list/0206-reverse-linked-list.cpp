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
    ListNode *prev=NULL;
    ListNode *solve(ListNode * head){
        if(head==NULL || head->next==NULL){
           prev=head;
            return head;
        }
        ListNode *p=solve(head->next);
        p->next=head;
        head->next=NULL;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
           solve(head);
           return prev;
    }
};