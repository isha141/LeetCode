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
                return {};
           queue<pair<TreeNode*,pair<int,int>>>q;
           q.push({root,{0,0}});
          map<int,map<int,multiset<int>>>mp;
           vector<vector<int>>ans;
            while(!q.empty()){
                 int t=q.size();
                while(t--){
                auto it=q.front();
                q.pop();
                int x=it.second.first;
                int y=it.second.second;
                TreeNode *node=it.first;
                mp[x][y].insert(node->val);
                if(node->left){
                    q.push({node->left,{x-1,y+1}});
                }
                if(node->right){
                    q.push({node->right,{x+1,y+1}});
                }
                }
            }
          for(auto it: mp){
               vector<int>ds;
              for(auto itr: it.second){
                  ds.insert(ds.end(),itr.second.begin(),itr.second.end());
              }
              ans.push_back(ds);
          }
          return ans;
    }
};