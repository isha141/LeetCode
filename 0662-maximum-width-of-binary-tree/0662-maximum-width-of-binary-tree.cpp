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
    int ans=0;
    int solve(TreeNode* root){
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size(); 
            int first=0;
            int last=0;
            for(int i=0;i<n;++i){
                   auto itr=q.front(); 
                q.pop();
                TreeNode* temp=itr.first;
                long long val=itr.second;
                if(i==0){
                    first=val;
                }
                if(i==n-1){
                    last=val;
                }
                if(temp->left)
                    q.push({temp->left,1ll*2*(val-first)+1});
                if(temp->right)
                    q.push({temp->right,1ll*2*(val-first)+2});
             }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        return solve(root);
    }
};