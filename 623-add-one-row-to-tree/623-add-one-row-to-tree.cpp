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
    TreeNode *solve(TreeNode *root,int val,int depth){
        if(depth==1){
        TreeNode *temp=new TreeNode(val);
            temp->left=root;
             return temp;
        } 
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            depth--;
            while(n--){
                auto itr=q.front();
                q.pop();
                if(depth==1){
                        TreeNode *temp=new TreeNode(val);
                    if(itr->left)
                        temp->left=itr->left;
                       itr->left=temp;   
                    
                         temp=new TreeNode(val);
                    if(itr->right){
                        temp->right=itr->right;
                    }
                        itr->right=temp;
                }
                else{
                    if(itr->left)
                        q.push(itr->left); 
                    if(itr->right)
                        q.push(itr->right);
                }
            }
            // depth--;
           }
        return root;
        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return root;
        return solve(root,val,depth);
    }
};