
class Solution { 
    private:
    ListNode * reverse(ListNode* head){
         ListNode * temp=head->next;
         head->next=NULL;
         while(temp!=NULL){
             ListNode * p=temp->next;
               temp->next=head;
              head=temp;
              temp=p;
         }
        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return head;
         int c=1;
         ListNode *p=head;
        while(p!=NULL){
            c++;
            p=p->next;
        }
        int temp=(c+1)/2;
        c=1; 
        p=head;
        while(c!=temp){
            p=p->next;
            c++;
        }
        ListNode *a=p; 
        // cout<<a->val<<"..";
        p=reverse(a); 
        while(p!=NULL){
            if(head->val!=p->val) return 0;
            p=p->next;
            head=head->next;
        }
        return 1;
    }
};