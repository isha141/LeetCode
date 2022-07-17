/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { 
    private:
    void parent(TreeNode *root,map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL) return;
        parent(root->left,mp);
        mp[root->left]=root;
        parent(root->right,mp);
        mp[root->right]=root;
    }  
    void solve(TreeNode *target,int k,map<TreeNode *,TreeNode *>&mp,vector<int>&ans){
       map<TreeNode*,bool>visited;
        queue<TreeNode *>q;
        q.push(target);
      visited[target]=1; 
        int d=0;
        while(!q.empty() && d!=k){
            int n=q.size();
            for(int i=0;i<n;++i){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=1;
                }
                if(temp->right && !visited[temp->right]){
                      q.push(temp->right);
                    visited[temp->right]=1;
                } 
                if(mp[temp] && !visited[mp[temp]]){
                    q.push(mp[temp]);
                    visited[mp[temp]]=1;
                }
            }
            d++;
        } 
        while(!q.empty()){
            ans.push_back(q.front()->val);
              q.pop();
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        map<TreeNode* ,TreeNode*>mp;
        if(root==NULL)
            return ans; 
        parent(root,mp); 
        solve(target,k,mp,ans);
        return ans;
    }
};