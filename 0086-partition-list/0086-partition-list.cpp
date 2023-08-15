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
    ListNode* partition(ListNode* head, int x) {
         if(head==NULL)
              return head;
         vector<int>prev,ds;
        ListNode *tail=head;
         while(tail!=NULL){
             if(tail->val>=x){
                 ds.push_back(tail->val);
             }
             else{
                 prev.push_back(tail->val);
             }
             tail=tail->next;
         }
         tail=head;
         for(auto itr: prev){
              tail->val=itr;
             tail=tail->next;
         }
         for(auto itr: ds){
             tail->val=itr;
             tail=tail->next;
         }
         return head;
    }
};