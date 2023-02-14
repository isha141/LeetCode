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
    vector<int>in;
    void inorder(TreeNode* root){
        if(root==NULL)
            return ;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
        return ;
    } 
    TreeNode * solve(int low,int high){
         if(low>=high)
             return NULL;
        int mid=(low+high)>>1;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=solve(low,mid);
        root->right=solve(mid+1,high);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
              return root;
        inorder(root); 
        return solve(0,in.size());
    }
};