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
    //1-->itself camera
    //0-->under camera
    //-1--> require monitor 
    int ans=0;
    void markparent(TreeNode *root,map<TreeNode *,TreeNode *>&mp){ 
        // if(root->left==NULL && root->right==NULL)
        if(root==NULL)
            return ;
        markparent(root->left,mp);
        markparent(root->right,mp);
        mp[root->left]=root;
        mp[root->right]=root;
    } 
    int solve(TreeNode *root,map<TreeNode *,TreeNode *>&mp)
    {
        if(root==NULL)
            return  0;
        int l=solve(root->left,mp);
        int r=solve(root->right,mp);
        if(l==-1 || r==-1){
            ans+=1; 
            return 1;
        }
        else if(l ==1 || r==1)
            return  0;
        else
            return -1;
        
            
            
    }
public:
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;  
        map<TreeNode *,TreeNode *>mp;
        markparent(root,mp); 
        int mon=1;
        if(solve(root,mp)==-1)
            ans++;
        return ans;
    }
};