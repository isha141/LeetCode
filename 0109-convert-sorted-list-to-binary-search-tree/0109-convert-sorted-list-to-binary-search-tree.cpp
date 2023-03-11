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
    vector<int>ds;
    void solve(ListNode * root){
         while(root!=NULL){
             ds.push_back(root->val);
             root=root->next;
         }
    } 
    TreeNode * preorder(int start,int end){
        if(start>end) return NULL; 
        int mid=(start+end)>>1;
        TreeNode * root=new TreeNode(ds[mid]);
        root->left=preorder(start,mid-1);
        root->right=preorder(mid+1,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        solve(head); 
        return  preorder(0,ds.size()-1);
    }
};