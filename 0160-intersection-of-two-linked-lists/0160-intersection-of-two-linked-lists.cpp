/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL) 
             return headB;
        if(headB==NULL) return headA;
        ListNode *h1=headA;
        ListNode *h2=headB;
        while(1){
               if(h1==h2)
                    return h1;
              h1=h1->next;
              h2=h2->next;
            if(h1==h2)
                    return h1;
              if(h1==NULL){
                  h1=headB;
              }
              if(h2==NULL){
                  h2=headA;
              }
            // if(h1==h2)
                    // return h1;
              
        }
        return nullptr;
    }
};