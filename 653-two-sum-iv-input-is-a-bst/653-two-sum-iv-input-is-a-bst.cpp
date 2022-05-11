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
class BSTIterator{
    private: 
    ////false--->next
    ////true--->  before
    stack<TreeNode *>s;
    bool reverse=true; 
    void inorder(TreeNode *root,bool reverse)
    {
        while(root!=NULL)
        {
           if(reverse==false)
           {
               s.push(root);
               root=root->left;
           }
            else{
                s.push(root);
                root=root->right;
            }
        }
    }
    public:
    BSTIterator(TreeNode *root,bool isreverse)
    {
        reverse=isreverse;
        inorder(root,reverse); 
    }
    // bool hasnext()
    // {
    //     return !s.empty();
    // }
    int next()
    {
        TreeNode *temp=s.top();
        s.pop();
        if(reverse==false)
        {
            inorder(temp->right,false);
        }
        else
            inorder(temp->left,true);
        return temp->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator obj1(root,false);
        BSTIterator   obj2(root,true);  
        int i=obj1.next();
        int j=obj2.next();
        while(i<j )
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=obj1.next();
            else
               j= obj2.next();
        }
        return false;
    }
};