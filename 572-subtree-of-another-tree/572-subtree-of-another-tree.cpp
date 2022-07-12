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
    bool check(TreeNode *root,TreeNode *subroot){
        if(root==NULL && subroot==NULL) return 1;
          if(root==NULL || subroot==NULL) return 0; 
        if(root->val!=subroot->val) return 0;
        bool left=check(root->left,subroot->left);
        bool right=check(root->right,subroot->right);
        return left && right;
    }
    private:
    bool solve(TreeNode *root,TreeNode *subroot){
        if(root==NULL)
            return 0;
            // return 0;
        if(root->val==subroot->val){
           if( check(root,subroot))
               return 1;
            
        }
         if(solve(root->left,subroot))
             return 1;
         if(solve(root->right,subroot))
             return 1; 
        else
        return 0;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { 
        bool flag=0; 
        if(root==NULL && subRoot==NULL)
            return 1;
        // cout<<root->val<<" "<<subRoot->val<<endl;
            // re;
        return solve(root,subRoot);
    }
};