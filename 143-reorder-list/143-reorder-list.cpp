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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return ;
        stack<ListNode*>s;
        ListNode* curr=head; 
        int n=0;
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->next;
            n++;
        } 
        curr=head;
        for(int j=0;j<n/2;j++)
        {
            ListNode* ptr=s.top();
            s.pop();
            ptr->next=curr->next;
            curr->next=ptr;
            curr=curr->next->next;
        }
        curr->next=NULL;
    }
};