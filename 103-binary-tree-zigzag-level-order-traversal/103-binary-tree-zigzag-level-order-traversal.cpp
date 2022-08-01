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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode *>q;
        q.push(root); 
        bool flag=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>ds(n,0); 
            int i=0; 
            int t=n;
            while(t--){
               auto *temp=q.front();
               q.pop();
            int index=flag?n-i-1: i;
                ds[index]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                i++;
            }
            flag=!flag;
            ans.push_back(ds);
        }
        return ans;
    }
};