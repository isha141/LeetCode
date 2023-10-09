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
    void solve(Node*node,Node *root,vector<Node*>&vis){
         if(node==NULL)
               return ;
        vis[root->val]=root;
         for(auto itr: node->neighbors){
               if(vis[itr->val]==NULL){
                   Node* curr=new Node(itr->val);
                   root->neighbors.push_back(curr);
                   solve(itr,curr,vis);
               }
               else{
                   root->neighbors.push_back(vis[itr->val]);
               }
         }
        return ;
    }
public:
    Node* cloneGraph(Node* node) {
         if(node==NULL) return {NULL};
         Node *root=new Node(node->val);
         vector<Node*>vis(101,NULL);
          solve(node,root,vis);
          return root;
    }
};