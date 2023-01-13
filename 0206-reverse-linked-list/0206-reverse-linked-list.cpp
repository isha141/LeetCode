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
    ListNode *solve(ListNode *head){
        ListNode *temp=head->next;
        head->next=NULL; 
        while(temp!=NULL){
         ListNode *p=temp->next;
            temp->next=head;
            head=temp;
            temp=p;
        }
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        return solve(head);
    }
};