/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
          if(head==NULL)
                return head;
        Node *dummy=new Node(0);
        Node *curr=dummy;
        stack<Node*>s;
        Node *root=head;
          while(root!=NULL || s.size()!=0){
                if(curr){
                    curr->child=NULL;
                }
                if(root==NULL){
                    if(s.size()){
                        curr->next=s.top();
                        s.top()->prev=curr;
                        s.pop();
                        curr->child=NULL;
                        curr=curr->next;
                        root=curr->next;
                    }
                }
                else if(root->child==NULL){
                    curr->next=root;
                    root->prev=curr;
                    root=root->next;
                    curr->child=NULL;
                    curr=curr->next;
                }
               else if(root->child){
                   Node *temp=root->next;
                    if(temp!=NULL){
                   temp->prev=NULL;
                   s.push(temp);
                    }
                   root->next=NULL;
                   curr->next=root;
                   root->prev=curr;
                   curr->child=NULL;
                   curr=curr->next; 
                   root=root->child;
              } 
          }
          curr->child=NULL;
          head=dummy->next;
          // while(head!=NULL){
          //     if(head->prev && head->next){
          //         cout<<head->prev->val<<";;"<<head->val<<"***"<<head->next->val<<endl;
          //     }
          //     head=head->next;
          // }
          dummy->next->prev=NULL;
         return dummy->next;
    }
};