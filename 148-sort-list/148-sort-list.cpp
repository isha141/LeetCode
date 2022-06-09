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
    ListNode*  middle(ListNode*  head){ 
        if(head==NULL || head->next==NULL) return head;
        ListNode*  slow=head;
        ListNode*  fast=head;
        while(slow && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){ 
        // if(head==NULL || head->next==NULL)
        //     return head;
        ListNode* temp=new ListNode(0);
        ListNode* res=temp;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        if(left)
            temp->next=left;
        else if(right)
            temp->next=right;
        return res->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*  left=head;
        ListNode*  mid=middle(head);
        ListNode*  right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        ListNode*  res=merge(left,right);
        return res;
    }
};