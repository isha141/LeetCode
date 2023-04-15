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
    TreeNode * solve(TreeNode * root){
        queue<TreeNode*>q;
        q.push(root); 
        root->val=0;
        while(!q.empty()){
            int n=q.size(); 
            int sum=0;
            vector<TreeNode *>ds;
            while(n--){
                auto itr=q.front();
                q.pop();
                ds.push_back(itr);
                if(itr->left){
                    sum+=itr->left->val;
                    q.push(itr->left);
                }
                if(itr->right){
                    sum+=itr->right->val;
                    q.push(itr->right);
                }
            }
            for(auto itr: ds){
                int temp=sum;
                if(itr->left)
                    temp-=itr->left->val;
                if(itr->right)
                    temp-=itr->right->val;
                if(itr->left)
                    itr->left->val=temp;
                if(itr->right)
                     itr->right->val=temp;
            }
        }
        return root;
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL) return root;
        return solve(root);  
    }
};