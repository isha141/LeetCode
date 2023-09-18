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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)
              return {{}};
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp;
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            TreeNode *head=itr.first;
            int x=itr.second.first;
            int y=itr.second.second;
            mp[x][y].insert(head->val);
            if(head->left)
                q.push({head->left,{x-1,y+1}});
            if(head->right){
                q.push({head->right,{x+1,y+1}});
            }
        }
        for(auto itr: mp){
            vector<int>ds;
            for(auto iit: itr.second){
                ds.insert(ds.end(),iit.second.begin(),iit.second.end());
            }
            ans.push_back(ds);
        }
        return ans;
    }
};