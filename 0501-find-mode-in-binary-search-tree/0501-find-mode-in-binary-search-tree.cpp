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
    void solve(TreeNode *root,map<int,int>&mp){
        if(root==NULL) 
            return ;
        solve(root->left,mp);
        solve(root->right,mp);
        if(root!=NULL)
            mp[root->val]++;
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        solve(root,mp);
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        int a=pq.top().first;
        while(!pq.empty() && pq.top().first==a){
             ans.push_back(pq.top().second);
              pq.pop();
        } 
        return ans;
    }
};