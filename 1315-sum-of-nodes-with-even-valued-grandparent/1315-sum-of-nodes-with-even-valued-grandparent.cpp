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
    void find_parent(TreeNode* root, map<TreeNode * ,TreeNode*>&parent){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL)
            return ;
       find_parent(root->left,parent); 
            if(root->left)
               parent[root->left]=root; 
       find_parent(root->right,parent); 
           if(root->right)
               parent[root->right]=root;
    }
    void solve(TreeNode * root,map<TreeNode * ,TreeNode*>&mp){
        if(root==NULL) return ; 
        solve(root->left,mp); 
        solve(root->right,mp); 
        if(root){ 
            // cout<<root->val<<":::"<<endl;
        if(mp.find(root)!=mp.end()){
                TreeNode * grand=mp[root];
            // cout<<grand->
                if(mp.find(grand)!=mp.end()){ 
                    int val=mp[grand]->val;
                    if((val)%2==0){
                        // cout<<root->val<<" "<<grand->val<<endl;
                        ans+=root->val;
                    }
                }
            }
        }
        return ;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        map<TreeNode * ,TreeNode*>parent;
        find_parent(root,parent);  
        // for(auto itr: parent)
            // cout<<itr.first->val<<" "<<itr.second->val<<endl;
        solve(root,parent);
        return ans;
    }
};
