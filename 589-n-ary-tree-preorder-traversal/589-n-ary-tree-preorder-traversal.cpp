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
    void solve(Node *root,vector<int>&ds)
    {
        if(root==NULL)
            return ;
        ds.push_back(root->val); 
        for(Node *child : root->children){
            solve(child,ds);
        }
    }
public:
    vector<int> preorder(Node* root) {
        if(root==NULL)
            return {};
        vector<int>ds;
          solve(root,ds);  
        return ds;
    }
};