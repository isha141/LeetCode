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
    queue<TreeNode *>q;
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
             return 0;
        q.push(root);
         int ans=INT_MIN;
        int level=1; 
        int res=0;
        while(!q.empty()){ 
            int t=q.size();
            int sum=0;
            while(t--){
                auto itr=q.front();
                 q.pop(); 
                sum+=itr->val;
                if(itr->left)
                    q.push(itr->left);
                if(itr->right)
                    q.push(itr->right);
            }
            if(ans<sum){
                ans=sum;
                res=level;
            }
            level++; 
            
            
        }
        return res;
    }
};