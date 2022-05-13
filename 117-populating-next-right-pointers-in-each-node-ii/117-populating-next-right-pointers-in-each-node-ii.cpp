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
public:
    Node* connect(Node* root) {
        Node* temp=root;
        if(root==NULL)
            return root;
        while(root!=NULL)
        {
            Node* temp=new Node(0);
            Node* current=temp;
            while(root!=NULL)
            {
                if(root->left!=NULL)
                {
                    current->next=root->left;
                    current=current->next;
                }
                if(root->right!=NULL)
                {
                    current->next=root->right;
                    current=current->next;
                }
                root=root->next;
            }
            root=temp->next;
        }
        return temp;
    }
};