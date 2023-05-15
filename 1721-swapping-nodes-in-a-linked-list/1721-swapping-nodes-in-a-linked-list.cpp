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
     ListNode* solve(ListNode * head,int k){
          int i=1;
           ListNode *temp=head;
          int n=1;
         while(temp->next!=NULL){
              temp=temp->next;
             n++;
         } 
         // n--; 
         // cout<<n<<"::"<<endl;
          ListNode *temp1=head; 
         ListNode * p,*q;
          while(temp1!=NULL){  
                if(i==k){
                    p=temp1;
                }
                 if(i==n-k+1){
                      q=temp1;
                 }
              i++;
              temp1=temp1->next;
          } 
          swap(p->val,q->val);
          return head;
     }
public:
    ListNode* swapNodes(ListNode* head, int k) {
       if(head==NULL)
             return head;
         return solve(head,k);
    }
};