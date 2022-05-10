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
    TreeNode* insuc(TreeNode* root)
    {
        while(root && root->left!=NULL)
            root=root->left;
        return root;
    } 
    TreeNode*  inpre(TreeNode*  root)
    {
        while(root && root->right)
            root=root->right;
        return root;
    } 
    int height(TreeNode*  root)
    {
        if(root==NULL)
            return 0;
        int x=height(root->left);
        int y=height(root->right);
         return x+y+1;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) { 
        if(root==NULL)
             return NULL ; 
        if(root->val==key && root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        if(root->val<key)
            root->right=deleteNode(root->right,key);
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        else
        {
            if(height(root->left)>height(root->right))
            {
               TreeNode* temp=inpre(root->left);
                root->val=temp->val;
                root->left=deleteNode(root->left,temp->val);
            }
            else{
                TreeNode* temp=insuc(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
            }
        }
        // else if(root->left==NULL){
        //     root->left=deleteNode(root->right,key); 
        // }
        // else if(root->right==NULL)
        //         root->right=deleteNode(root->left,key);
        return root;
        
    }
};