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
class info{
    public :
    int mini;
    int maxi;
    int value;  
    info(int mini,int maxi,int value)
    {
        this->mini=mini;
        this->maxi=maxi;
        this->value=value;
    }
    
};
class Solution {  
    int ans=0;
    private:
    info largest(TreeNode *root){
        if(root==NULL)
            return {INT_MAX,INT_MIN,0};
        else if(root->left==NULL && root->right==NULL)
            return {root->val,root->val,root->val};
        auto left=largest(root->left);
         auto right=largest(root->right); 
        // cout<<ans<<" ";
        if(root->val > left.maxi && root->val < right.mini){ 
                    ans=max(ans,left.value+right.value+root->val); 
            return {min(root->val,left.mini),max(root->val,right.maxi),left.value+right.value+root->val};
        } 
        else{
            return {INT_MIN,INT_MAX,max(left.value,right.value)}; 
            // ans=max(ans,max(left.value,right.value));
        }
    } 
public:
    int maxSumBST(TreeNode* root) {
        if(root==NULL)
            return 0;
       int temp=largest(root).value; 
        // cout<<ans<<" ";
        return max(temp,ans);
    }
};