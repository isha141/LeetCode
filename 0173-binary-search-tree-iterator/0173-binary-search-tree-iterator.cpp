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
    stack<TreeNode*>s;
     
public:
    void inorder(TreeNode *root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        auto itr=s.top();
        s.pop();
        inorder(itr->right);
        return itr->val;
    }
    
    bool hasNext() {
        if(s.size()) return 1;
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */