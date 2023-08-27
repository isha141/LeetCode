/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node *root=head;
        while(root!=NULL){
            Node *temp=new Node(root->val);
             temp->next=root->next;
              root->next=temp;
            root=root->next->next;
        }
        root=head;
        while(root!=NULL){
            Node *rand=root->random;
            if(rand!=NULL){
                root->next->random=rand->next;
            }
            root=root->next->next;
        }
        root=head;
        Node *dummy=new Node(0);
        Node *p=dummy;
        while(root!=NULL){
            p->next=root->next;
            p=p->next;
            root->next=root->next->next;
            root=root->next;
        }
         return dummy->next;
    }
};