/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    int solve(ListNode *h1,ListNode *h2){
          int len1=0;
          int len2=0;
          while(h1!=NULL){
              len1+=1;
              h1=h1->next;
          }
          while(h2!=NULL){
              len2+=1;
              h2=h2->next;
          }
        return (len1-len2);
    }
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
           if(h1==NULL)
                 return h2;
           if(h2==NULL)
                 return h1;
           int diff=solve(h1,h2);
           if(diff<0){
                 while(diff!=0){
                     h2=h2->next;
                     diff++;
                 }
           }
           else{
               while(diff>0){
                   h1=h1->next;
                   diff--;
               }
           } 
            while(h1 && h2){
                  if(h1==h2)
                        return h1;
                h1=h1->next;
                h2=h2->next;
            }
          return  NULL;
    }
};