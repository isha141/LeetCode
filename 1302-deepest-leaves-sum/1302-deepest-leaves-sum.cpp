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
    int solve(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        { 
            sum=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
             TreeNode* temp=q.front();
                sum+=temp->val;
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return sum;
        
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        return solve(root);
    }
};