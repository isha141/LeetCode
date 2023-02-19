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
        vector<vector<int>>ans;
    void solve(TreeNode * root){
        queue<TreeNode *>q;
        q.push(root); 
        bool flag=0;
        while(!q.empty()){ 
            int n=q.size();
            vector<int>ds(n,0);
            for(int i=0;i<n;++i){ 
                auto itr=q.front();
                q.pop();
                if(flag)
                    ds[n-i-1]=itr->val;
                else
                    ds[i]=itr->val;
                if(itr->left)
                    q.push(itr->left);
                if(itr->right)
                    q.push(itr->right);
            }
            ans.push_back(ds); 
            flag=!flag;
        }
        return ;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        solve(root);
        return ans;
    }
};