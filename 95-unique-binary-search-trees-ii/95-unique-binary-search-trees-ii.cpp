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
     
   vector<TreeNode*> solve(int l,int r){
        if(l>r)
            return {NULL}; 
        vector<TreeNode*>ans;
        for(int i=l;i<=r;++i){
            vector<TreeNode*>left=solve(l,i-1);
            vector<TreeNode*>right=solve(i+1,r);
            for(auto itr: left){
                for(auto itt: right){
                    TreeNode *root=new TreeNode(i);
                    root->left=itr;
                    root->right=itt;
                    ans.push_back(root);
                }
            }
        } 
       return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>temp=solve(1,n); 
        for(auto itr: temp)
            cout<<itr->val<<" ";
        return temp;
    }
};