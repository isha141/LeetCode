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
    void solve(Node * node,vector<Node*>&vis,Node* root){
          vis[node->val]=root;
        for(auto itr: node->neighbors){
            if(!vis[itr->val]){
                Node * temp=new Node(itr->val);
                root->neighbors.push_back(temp);
                solve(itr,vis,temp);
            } 
            else{
                root->neighbors.push_back(vis[itr->val]);
                
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node * root=new Node(node->val);
        vector<Node*>vis(101,NULL);
         solve(node,vis,root); 
        return root;
        
    }
};