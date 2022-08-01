/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution { 
    private:
    Node  *solve(Node *root)
    {
        queue<Node *>q;
        q.push(root); 
        Node *head=root;
        while(!q.empty())
        {
            int n=q.size(); 
            while(n--){
                Node *temp=q.front();
                q.pop(); 
                temp->next==NULL;
                if(n==0) 
                      temp->next=NULL;
                else
                  temp->next=q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
           } 
        }
        return head;
    }
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        return solve(root);
    }
};