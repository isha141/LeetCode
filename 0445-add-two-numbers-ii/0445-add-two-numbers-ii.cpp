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
    ListNode *reverse(ListNode *root){
         ListNode *temp=root->next;
         root->next=NULL;
         while(temp!=NULL){
             ListNode *p=temp->next;
             temp->next=root;
             root=temp;
             temp=p;
         }
        return root;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
              return l2;
        if(l2==NULL)
             return l1;
        l1=reverse(l1);
        l2=reverse(l2); 
        ListNode *prev=new ListNode(0);
        ListNode *p=prev;
        int carry=0;
        while(l1 || l2 || carry){
            int sum=carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode *temp=new ListNode(sum%10);
                carry=sum/10;
            p->next=temp;
            p=temp;
        }
        ListNode *res=reverse(prev->next);
        return res;
    }
};