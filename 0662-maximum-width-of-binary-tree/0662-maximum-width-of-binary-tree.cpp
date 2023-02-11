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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){ 
            int mini=INT_MAX;
            int maxi=INT_MIN;
            int n=q.size();
            while(n--){
                auto itr=q.front();
                q.pop();
               TreeNode * node=itr.first;
                int ind=itr.second;
                mini=min(mini,ind);
                maxi=max(mini,ind);
                if(node->left)
                    q.push({node->left,2*(long long)(ind-mini)+1});
                if(node->right)
                    q.push({node->right,2*(long long)(ind-mini)+2});
                ans=max(ans,maxi-mini+1);
            }
        }
        return ans;
    }
};