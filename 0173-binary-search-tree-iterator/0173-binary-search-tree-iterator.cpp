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
class BSTIterator { 
    vector<int>in;
    int k=0;
    void solve(TreeNode * root){
        if(root==NULL)
            return;
        solve(root->left);
        in.push_back(root->val);
        solve(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        if(root==NULL) return;
        solve(root);    
    }
    
    int next() {
        // if(k<=in.size()-1)
             return in[k++];
    }
    
    bool hasNext() {
        if(k<=in.size()-1)
            return 1;
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */