/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution { 
    private: 
    TreeNode * first=NULL;
        TreeNode * middle=NULL;
        TreeNode * last=NULL;
    TreeNode *prev=NULL; 
    private:
    void inorder(TreeNode *root) 
    {
        if(root==NULL)
            return ;
        inorder(root->left); 
        if(prev!=NULL && root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else {
               last=root;
            }
        }
        prev=root;
        inorder(root->right);
        return ;
    }
    public:
       void recoverTree(TreeNode *root) { 
        inorder(root); 
        if(last==NULL)
        swap(first->val,middle->val);
        else if(first->val > last->val)
            swap(first->val,last->val);
        else 
            swap(last->val,middle->val);
        return ;
    }
};