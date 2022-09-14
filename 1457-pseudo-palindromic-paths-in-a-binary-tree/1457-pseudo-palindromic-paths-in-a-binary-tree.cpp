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
class Solution  {  
    int c=0; 
    int mp[10]={0};
    private: 
    void solve(TreeNode *root,string &s){
        if(root==NULL)
            return ; 
        s+=to_string(root->val);  
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL){
              int temp=0;
            for(auto itr: mp){ 
                // cout<<itr<<" ";
                if(itr%2)
                    temp++;
            }
            // cout<<endl;
            if(temp<=1)
                c++; 
            mp[root->val]--;
            return ;
        }
        solve(root->left,s);  
        solve(root->right,s);  
        // cout<<root->val<<endl;
        mp[root->val]-=1;
    
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL) return 0; 
        string s="";
         solve(root,s); 
        return c;
    }
};