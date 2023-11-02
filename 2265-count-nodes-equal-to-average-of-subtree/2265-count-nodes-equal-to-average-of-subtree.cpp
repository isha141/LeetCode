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
    int ans=0;
    void ok(TreeNode *root){
        if(root==NULL)
              return ;
        queue<TreeNode*>q;
        int c=1;
        int sum=root->val;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                sum+=itr->val;
                c+=1;
                if(itr->left)
                    q.push(itr->left);
                if(itr->right)
                    q.push(itr->right);
            }
        }
        int avg=0;
        // if(c!=0)
        avg=(sum)/c;
        if(root->val==avg)
            ans+=1;
    }
    void solve(TreeNode *root,int sum,int c){
        if(root==NULL)
              return ;
        ok(root);
        solve(root->left,sum,c);
        solve(root->right,sum,c);
    }
public:
    int averageOfSubtree(TreeNode* root) {
          if(root==NULL) return 0;
          int sum=0;
          int c=0;
          solve(root,sum,c);
          return ans;
    }
};