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
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { 
        if(l1==NULL)
            return l2;
        else if(l2==NULL) return l1;
        ListNode* res=NULL;
        ListNode* temp=NULL;
        if(l1->val<=l2->val){
            temp=l1;
        }
        else
            swap(l1,l2);
         res=l1;
        while(l1!=NULL && l2!=NULL)
        { 
            temp=NULL;
            while(l1!=NULL  && l1->val<=l2->val)
            { 
                temp=l1;
                l1=l1->next;
            } 
                temp->next=l2; 
                swap(l1,l2);
        } 
        if(l2)
            temp->next=l2;
        return res;
    }
};