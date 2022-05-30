/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution { 
private:
    void solve(Node *node,Node *copy,vector<Node*>&vis)
    {  
        vis[copy->val]=copy;
        for(Node * n: node->neighbors)
        {
            if(vis[n->val]==NULL)
            {
                Node *temp=new Node(n->val);
                copy->neighbors.push_back(temp);
                solve(n,temp,vis);
            }
            else
                copy->neighbors.push_back(vis[n->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node *copy=new Node(node->val); 
        vector<Node*>vis(101,NULL);
        solve(node, copy,vis);
        return copy;
    }
};