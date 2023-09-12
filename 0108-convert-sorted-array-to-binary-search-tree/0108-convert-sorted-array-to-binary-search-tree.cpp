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
    TreeNode *solve(vector<int>&nums){
        if(nums.size()==0)
              return NULL;
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        int mid=nums.size()/2;  
        TreeNode *root=new TreeNode(nums[mid]);
        vector<int>lefti(nums.begin(),nums.begin()+mid);
        vector<int>righti(nums.begin()+mid+1,nums.end());
        TreeNode *left=solve(lefti);
        TreeNode *right=solve(righti);
         root->left=left;
         root->right=right;
         return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         int n=nums.size(); 
          return solve(nums);
    }
};