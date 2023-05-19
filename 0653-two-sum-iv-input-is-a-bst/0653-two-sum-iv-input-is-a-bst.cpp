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
class Bst{
    public:
     stack<TreeNode*>s;
      bool reverse=1;
       Bst(TreeNode* root,bool isrev){
            reverse=isrev;
            inorder(root,reverse);
       } 
     void inorder(TreeNode* root,bool reverse){
           while(root!=NULL){
               if(reverse==0){
                   s.push(root);
                   root=root->left;
               }
               else{
                   s.push(root);
                   root=root->right;
               }
           } 
     }
     int next(){
          TreeNode * temp=s.top();
           s.pop();
           if(reverse==0){
               inorder(temp->right,0);
           }
           else{
               inorder(temp->left,1);
           }
         return temp->val;
     }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) { 
        if(root==NULL) return 0;
        Bst obj1(root,0);
        Bst obj2(root,1);
        int i=obj1.next();
        int j=obj2.next();
        while(i<j){
            if(i+j==k)
                return 1;
            if(i+j<k){
                i=obj1.next();
            }
            else{
                j=obj2.next();
            }
        }
        return 0;
    }
};