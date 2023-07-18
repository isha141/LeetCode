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
    ListNode *reverse(ListNode *head){
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode *head=NULL;
        ListNode *prev=NULL;
        int carry=0;
         while(l1!=NULL && l2!=NULL){
             int temp=(l1->val)+(l2->val)+carry;
             if(prev==NULL){
                 prev=new ListNode(temp%10);
                 head=prev;
             } 
             else{
                 prev->next=new ListNode(temp%10);
                 prev=prev->next;
             }  
             carry=temp/10; 
             l1=l1->next;
             l2=l2->next;
         }
        while(l1!=NULL){ 
            int temp=(l1->val)+carry; 
            prev->next=new ListNode(temp%10);
            carry=temp/10;
            prev=prev->next;
            l1=l1->next;
        }
         while(l2!=NULL){ 
            int temp=(l2->val)+carry;
            prev->next=new ListNode(temp%10);
            carry=temp/10;
            prev=prev->next;
            l2=l2->next;
        }
        if(carry){
            prev->next=new ListNode(carry);
            prev=prev->next;
        }
        head=reverse(head);
        return head;
    }
};