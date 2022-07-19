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
         vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode *,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto itr=q.front();
                TreeNode *temp=itr.first;
                int x=itr.second.first;
                int y=itr.second.second; 
                q.pop();
                mp[x][y].insert(temp->val);
                if(temp->left)
                    q.push({temp->left,{x-1,y+1}});
                if(temp->right)
                    q.push({temp->right,{x+1,y+1}});
            }
        }
        for(auto itr: mp){
            vector<int>ds;
            for(auto itt: itr.second){
                ds.insert(ds.end(),itt.second.begin(),itt.second.end());
            }
            ans.push_back(ds);
        }
        return ans;
    }
};