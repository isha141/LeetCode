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
    map<int,int>l,r; 
    int maxh=0;
    void preheight(TreeNode * root,int h){
        if(root==NULL)
            return ;
        l[root->val]=maxh;
         maxh=max(maxh,h);
       preheight(root->left,h+1);
       preheight(root->right,h+1);
        // l[root->val]=max()
       } 
    void postheight(TreeNode*root,int h){
        if(root==NULL){
           return ; 
        }
        r[root->val]=maxh;
        maxh=max(maxh,h);
        postheight(root->right,h+1);
        postheight(root->left,h+1);
        
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
         vector<int>ans;
        if(root==NULL) return ans;
        preheight(root,0); 
        maxh=0;
        postheight(root,0); 
        // for(auto itr: l)
            // cout<<itr.first<<" "<<itr.second<<endl;
        // cout<<"***"<<endl;
        // for(auto itr: r)
            // cout<<itr.first<<" "<<itr.second<<endl;
        for(auto itr: q){
            ans.push_back(max(l[itr],r[itr]));
        }
        return ans;
        
    }
};