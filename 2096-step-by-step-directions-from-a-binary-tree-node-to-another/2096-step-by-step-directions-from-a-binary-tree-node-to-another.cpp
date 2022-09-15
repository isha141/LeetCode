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
    TreeNode *temp;
    unordered_map<TreeNode *,TreeNode *>mp;
    string ans=""; 
    unordered_set<int>s1;
    // void get_parent(TreeNode *root,int start)
    // {
    //     if(root==NULL) return ;
    //     if(root->val==start){
    //         temp=root;
    //     }
    //     get_parent(root->left,start);
    //     get_parent(root->right,start); 
    //     if(root->left)
    //         mp[root->left]=root;
    //     if(root->right)
    //         mp[root->right]=root;
    // }  
    TreeNode *get_lca(TreeNode *root,int start,int dest)
    {
        if(root==NULL) return NULL;
        if(root->val==start || root->val==dest)
            return root;
        TreeNode *left=get_lca(root->left,start,dest);
        TreeNode *right=get_lca(root->right,start,dest);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }  
   bool solve(TreeNode *head,int dest,string &s)
    {
        if(head==NULL)
            return 0;
        if(head->val==dest){
            ans=s; 
        return  1;
        } 
        s+='L';
        if(solve(head->left,dest,s))
            return 1;
       s.pop_back();
       s+='R';
       if(solve(head->right,dest,s))
         return 1;
       s.pop_back(); 
       return 0;
    }
    
public:
    string getDirections(TreeNode* root, int start, int dest) {
        if(root==NULL) return ""; 
        // get_parent(root,start);
        string s=""; 
        TreeNode *head=get_lca(root,start,dest);
        solve(head,start,s);   
       for(int i=0;i<s.size();++i)
           s[i]='U';
        solve(head,dest,s);
        return ans;
    }
};