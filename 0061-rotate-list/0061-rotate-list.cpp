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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode *root=head;
        int ans=0;
        while(root!=NULL){
            root=root->next;
            ans+=1;
        }
        k%=ans;
        if(k==0)
              return  head;
        root=head;
        int temp=ans-k;
        ListNode *prev=NULL;
        while(root!=NULL && temp>0){
            prev=root;
            root=root->next;
            temp-=1;
        }
        ListNode *mid=root;
        ListNode *res=mid;
        prev->next=NULL;
        while(mid->next!=NULL){
            mid=mid->next;
        }
        mid->next=head;
         return res;
    }
};