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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        int i=1;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(i<left){
            prev=prev->next;
            i++;
        }
        ListNode* tail=prev->next;
        for(int i=0;i<right-left;++i){
            ListNode *p=tail->next;
            tail->next=p->next;
            p->next=prev->next;
            prev->next=p;
        }
        return dummy->next;
    }
};