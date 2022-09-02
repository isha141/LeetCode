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
    void solve(TreeNode *root,vector<double>&ans)
    {
        queue<TreeNode *>q;
        q.push(root); 
        double sum=0;
        while(!q.empty()){
            int n=q.size();
            int c=0;
            while(n--){
                auto temp=q.front();
                q.pop();
                c++;
                sum+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            double t=sum/(c*1.0);
            sum=0;
            ans.push_back(t);
        }
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<double>ans;
        solve(root,ans);
        return ans;
    }
};