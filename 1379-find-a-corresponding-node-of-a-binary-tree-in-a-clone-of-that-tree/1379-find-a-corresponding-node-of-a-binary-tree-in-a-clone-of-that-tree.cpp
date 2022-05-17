/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o1, TreeNode* o2,TreeNode* target) {
        if(!o2)
            return NULL; 
        if(o1==target)
            return o2;
     return  (getTargetCopy(o1->left,o2->left,target)==NULL)?getTargetCopy(o1->right,o2->right,target):getTargetCopy(o1->left,o2->left,target);
    }
};