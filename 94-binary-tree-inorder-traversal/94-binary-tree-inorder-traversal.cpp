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
    void solve(TreeNode *root,vector<int>&ans)
    {
        stack<TreeNode *>s;
        // s.push(root); 
        TreeNode *curr=root;
        while(!s.empty() || curr!=NULL){
            if(curr){
                s.push(curr); 
                curr=curr->left;
            }
            else{  
                if(s.size()==0)
                    return ;
                ans.push_back(s.top()->val); 
                TreeNode *temp=s.top();
                s.pop();
                curr=temp->right;
            }
        }
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int>ans;
     solve(root,ans);
        return ans;
    }
};