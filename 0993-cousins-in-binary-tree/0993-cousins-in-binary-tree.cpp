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
   bool solve(TreeNode* root,int x,int y){
        queue<TreeNode *>q;
        q.push(root); 
        map<int,pair<int,int>>mp; 
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){ 
                auto itr=q.front(); 
                q.pop();
               TreeNode * node=itr;
                if(node->left){
                    mp[node->left->val]={node->val,level}; 
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right->val]={node->val,level};
                     q.push(node->right);
                }
            }
            level++;
        }
        if(mp.find(x)==mp.end() || mp.find(y)==mp.end()){
            return 0;
        }
        auto it1=mp[x];
        auto it2=mp[y];
        if(it1.first!=it2.first && it1.second==it2.second)
               return 1;
        return 0;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return 0;
        return solve(root,x,y);
    }
};