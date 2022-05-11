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
    private: 
    void inorder(TreeNode* root,stack<TreeNode*> &s)
    {
        while(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
    }
    stack<TreeNode*>s;
public:
    BSTIterator(TreeNode* root) {
        inorder(root,s);
    }
    
    int next() {
        TreeNode * temp=s.top();
        s.pop();
        inorder(temp->right,s);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */