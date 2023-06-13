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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
          if(des.size()==0)
                return NULL; 
        set<TreeNode *>s;
          map<int,TreeNode *>mp; 
          map<int,TreeNode*>parent; 
          map<int,TreeNode*>parent1;
          int n=des.size();
          for(int i=0;i<n;++i){
                int par=des[i][0];
                int curr=des[i][1];
                 TreeNode *current,*paren;
                if(mp.find(curr)!=mp.end()){
                      current=mp[curr];
                }     
                else{
                     current=new TreeNode(curr);
                }
                if(parent.find(par)!=parent.end()){
                     paren=parent[par];
                }
                else if(parent1.find(par)!=parent1.end()){
                      paren=parent1[par];
                }
                else{
                     paren=new TreeNode(par);
                }
                if(des[i][2]==0){
                    paren->right=current;
                } 
                else{
                    paren->left=current;
                }
                mp[curr]=current; 
                mp[par]=paren;
                parent[curr]=current; 
                parent1[paren->val]=paren;
                s.insert(current);
                s.insert(paren);
         } 
        TreeNode *root;
         for(auto itr=s.begin();itr!=s.end();++itr){
             if(parent.find((*itr)->val)==parent.end()){
                 root=*itr;
             }
         }
        return root;
    }
};