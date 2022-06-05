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
    ListNode* reverse(ListNode* head)
    {
        ListNode* temp=head->next;
        head->next=NULL;
        while(temp!=NULL)
        {
            ListNode* p=temp->next;
            temp->next=head;
            head=temp;
            temp=p;
        }
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        l1=reverse(l1);
        l2=reverse(l2);  
        int carry=0; 
        ListNode* dummy=new ListNode(0);
    ListNode* prev=dummy;
        while(l1!=NULL ||  l2!=NULL || carry)
        {   
            int sum=0;
            if(l1){
              sum+=l1->val;  
            l1=l1->next;}
            if(l2){
                sum+=l2->val; 
            l2=l2->next;}
            sum+=carry;   
           ListNode* temp=new ListNode(sum%10); 
              carry=sum/10;
            prev->next=temp;
            prev=temp;
        }
        ListNode* temp=dummy->next;
        temp=reverse(temp);
        return temp; 
        // return dummy->next;
    }
};