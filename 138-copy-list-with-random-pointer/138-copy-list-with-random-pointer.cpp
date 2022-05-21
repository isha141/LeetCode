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
        Node *dummy=new Node(0);
        dummy->next=head;
        while(head!=NULL)
        {
            Node *temp=new Node(head->val);
            temp->next=NULL;
            temp->next=head->next;
            head->next=temp;
            head=head->next->next;
        } 
        head=dummy->next;
        while(head!=NULL)
        {
          Node *temp=head->next; 
            if(head->random!=NULL)
            temp->random=head->random->next; 
            else
                temp->random=NULL;
            head=head->next->next;
        }
        head=dummy->next; 
        Node *iter=dummy;
         Node *pseudo=dummy;
        while(head!=NULL)
        { 
            Node *temp=head->next->next;
            iter->next=head->next;
            head->next=temp;
            iter=iter->next; 
            head=head->next;
        }
        return pseudo->next;
        
    }
};