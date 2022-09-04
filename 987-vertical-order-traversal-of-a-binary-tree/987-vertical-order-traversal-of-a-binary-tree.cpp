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
    void solve(TreeNode *root,int x,int y,map<int,map<int,multiset<int>>>&mp)
    {
        if(root==NULL)
            return ;
        mp[x][y].insert(root->val);
        solve(root->left,x-1,y+1,mp); 
        solve(root->right,x+1,y+1,mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
    map<int,map<int,multiset<int>>>mp;
        solve(root,0,0,mp);
        for(auto itr: mp){
            vector<int>ds;
            for(auto it: itr.second){
                ds.insert(ds.end(),it.second.begin(),it.second.end());
            }
            ans.push_back(ds);
        }
        return ans;
    }
};