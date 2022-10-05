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
   void solve(TreeNode *root,int val,int depth){
        if(root==NULL)
            return ; 
        // if(depth==1)
        //     return;
       if(depth==1){
            TreeNode *temp=new TreeNode(val); 
            if(root->left)
                temp->left=root->left; 
           root->left=temp;
            // return temp; 
            temp=new TreeNode(val);
            if(root->right)
                temp->right=root->right;
            root->right=temp;
            return ;
        }
        solve(root->left,val,depth-1);
        
        solve(root->right,val,depth-1);
        // return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return root; 
        if(depth==1){
            TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        solve(root,val,depth-1); 
        return root;
    }
};