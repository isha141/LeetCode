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
    ListNode *solve(ListNode* a,ListNode*b){
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                curr->next=a;
                curr=curr->next;
                a=a->next;
            }
            else{
                curr->next=b;
                curr=curr->next;
                b=b->next;
            }
        }
        while(a!=NULL){
            curr->next=a;
            curr=curr->next;
            a=a->next;
        }
        while(b!=NULL){
            curr->next=b;
            curr=curr->next;
            b=b->next;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>&list) {
         int n=list.size();
         if(n==0)
               return NULL;
         sort(list.begin(),list.end());
         ListNode *dummy=new  ListNode(0);
         if(list[0]!=NULL)
         dummy->next=list[0];
         for(int i=1;i<n;i++){
             dummy->next=solve(dummy->next,list[i]);
         }
          return dummy->next?dummy->next:NULL;
    }
};