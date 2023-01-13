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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL)
            return l1==NULL?l2:l1;
        ListNode *head=l1; 
        int carry=0;  
        ListNode * res=head;
        ListNode * prev=head;
        while(l1 && l2){
            int temp=(l1->val+l2->val)+carry;
            carry=temp/10;
            head->val=temp%10; 
            prev=head;
            head=head->next; 
            l1=l1->next;
            l2=l2->next;
        }  
        prev->next=NULL;
        head=prev;
        while(l1){
            ListNode *temp=new ListNode(0);
            int value=l1->val+carry;
              carry=value/10;
             temp->val=value%10; 
            // head->val=temp->val;
             head->next=temp;
            head=temp;
            l1=l1->next;
        }
        while(l2){
            ListNode *temp=new ListNode(0);
             int value=l2->val+carry;
             carry=value/10; 
            temp->val=value%10;
             // head->val=temp->val;
             head->next=temp;
             head=temp;
             l2=l2->next;
        }
        if(carry)
            head->next=new ListNode(carry); 
        return res;
    }
};