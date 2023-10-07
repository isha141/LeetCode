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
    TreeNode *solve(int start,int end,vector<int>&nums){
        if(start>end)
             return NULL;
        if(start==end){
             return new TreeNode(nums[start]);
        }
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        TreeNode *left=solve(start,mid-1,nums);
        TreeNode *right=solve(mid+1,end,nums);
        root->left=left;
        root->right=right;
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          int n=nums.size();
          return solve(0,n-1,nums);
    }
};