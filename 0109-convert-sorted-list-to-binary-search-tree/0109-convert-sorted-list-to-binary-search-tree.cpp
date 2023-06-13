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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {  
    private:
    ListNode *head;
    TreeNode * solve(int low,int high){
          if(low>high)
               return NULL;
          int mid=(low+high)>>1;
          TreeNode *leftnode=solve(low+1,mid);
          TreeNode * root=new TreeNode(head->val);
          head=head->next;
          root->left=leftnode;
          TreeNode *rightnode=solve(mid+1,high);
          root->right=rightnode;
          return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
          if(head==NULL) return NULL;
          int high=0; 
           this->head=head;
           while(head!=NULL){
                 high+=1;
                head=head->next;
           }
          return solve(0,high-1);
    }
};