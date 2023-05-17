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
    int pairSum(ListNode* head) {
         if(head==NULL) return 0;
         int ans=0;
         vector<int>ds;
         while(head!=NULL){
              ds.push_back(head->val);
              head=head->next;
         } 
        int n=ds.size();
          for(int i=0;i<ds.size()/2;++i){
                ans=max(ans,ds[i]+ds[n-i-1]);
          }
          return ans;
    }
};