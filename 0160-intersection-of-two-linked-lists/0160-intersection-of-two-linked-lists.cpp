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
         if(headA==NULL || headB==NULL)
               return headA;
         ListNode *root1=headA;
         ListNode *root2=headB;
        int count=0;
         while(count<=2){
             if(root1==NULL){
                 count+=1;
                 root1=headB;
             }
             if(root2==NULL){
                 count+=1;
                 root2=headA;
             }
             if(root1==root2){
                  return root2;
             }
             root1=root1->next;
              root2=root2->next;
         }
         return NULL;
    }
};