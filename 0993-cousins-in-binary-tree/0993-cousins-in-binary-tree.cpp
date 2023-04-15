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
    bool solve(TreeNode * root,int x,int y){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(); 
            bool fx=0;
            bool fy=0;
            while(n--){
                auto itr=q.front();
                q.pop();
                 if(itr->val==x) 
                     fx=1;
                if(itr->val==y){
                    fy=1;
                }
                if(itr->left && itr->right){
                    if((itr->left->val==x && itr->right->val==y) || (itr->right->val==x && itr->left->val==y))
                          return 0;
                }
                if(itr->left)
                    q.push(itr->left);
                if(itr->right)
                    q.push(itr->right);
            }
            if(fx && fy)
                return 1;
        }
        return 0;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return 1;
        return solve(root,x,y);
    }
};