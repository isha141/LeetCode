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
    ListNode *temp;
    ListNode *solve(ListNode *head,ListNode *prev){
        if(head==NULL || head->next==NULL){ 
            temp=head;
            return head;
        }
        head=solve(head->next,head->next); 
        cout<<prev->val<<" ";
        head->next=prev; 
        head=prev;
        prev->next=NULL;
        return head;  
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        solve(head,head); 
        return temp;
    }
};