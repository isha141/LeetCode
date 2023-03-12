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
    ListNode * solve(ListNode * h1,ListNode * h2){
          ListNode * dummy=new ListNode (0); 
         ListNode * prev=NULL; 
        if(h1==NULL ) return h2;
        if(h2==NULL) return h1;
           if(h1->val<h2->val){
                prev=h1;
               h1=h1->next;
           }
           else{
               prev=h2;
               h2=h2->next;
           } 
         dummy->next=prev;
        while(h1!=NULL && h2 !=NULL){
                if(h1->val<h2->val){
                    prev->next=h1; 
                    prev=h1;
                    h1=h1->next;
                }
            else{
                prev->next=h2; 
                prev=h2;
                h2=h2->next;
            }
        } 
          if(h1){
              prev->next=h1;
          }
        else if(h2){
            prev->next=h2;
        } 
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
          if(l.size()==0){
              return NULL;
          } 
           ListNode * head=NULL;
          if(l.size()==1){
            return  l[0];
          } 
         head=solve(l[0],l[1]);
        ListNode * temp=head;
        cout<<endl;
        for(int i=2;i<l.size();++i){
            head=solve(head,l[i]); 
            ListNode * temp=head;
            // while(temp!=NULL){
                 // cout<<temp->val<<",,";
                // temp=temp->next;
            // }
        }
        return head;
          
    }
};