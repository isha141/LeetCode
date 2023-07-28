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
    vector<TreeNode*>solve(int n){ 
        vector<TreeNode*>ans;
        if(n<0 || n==0){
            return ans;
        }
        if(n%2==0){
            return ans;
        } 
        if(n==1){
        TreeNode *root=new TreeNode(0);
        ans.push_back(root);
        } 
         vector<TreeNode*>left,right;
        for(int j=1;j<n;j+=2){
             left=solve(j);
             right=solve(n-j-1);
        for(int i=0;i<left.size();++i){
            for(int j=0;j<right.size();++j){
                TreeNode *root=new TreeNode(0);
                root->left=left[i];
                root->right=right[j];
                ans.push_back(root);
            }
           }
        }
        return ans;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};