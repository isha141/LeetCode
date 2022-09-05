/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution { 
    private:
    void solve(Node *root, vector<vector<int>>&ans)
    {
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>ds;
            while(n--)
            {
                Node *itr=q.front();
                q.pop(); 
                ds.push_back(itr->val);
                for(auto it: itr->children){
                    q.push(it);
                }
            }
            ans.push_back(ds);
        }
        return ;
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        solve(root,ans);
        return ans;
    }
};