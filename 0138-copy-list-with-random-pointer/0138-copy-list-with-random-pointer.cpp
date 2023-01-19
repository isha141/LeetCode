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
        Node * a=head;
        while(head!=NULL){
            Node * temp=head->next; 
            Node * p=new Node(head->val); 
            p->next=NULL;
            p->val=head->val;
            head->next=p;
            p->next=temp; 
            head=head->next->next;
        }
        head=a;
        while(head!=NULL){
            Node * temp=head->random; 
            if(temp!=NULL){
            head->next->random=temp->next;
            }
            else{
                head->next->random=NULL;
            }
            head=head->next->next;
        }
        head=a;
        Node * dummy=new Node(0);
        dummy->next=head->next;
        Node * p=dummy;
        // cout<<"HYYH"<<endl;
        while(head!=NULL){ 
             // cout<<head->val<<"..."<<head->next->val<<endl;
            // if(p==NULL){
            //     p=head->next;
            // }
            // else{
                p->next=head->next;
            // }
            p=p->next; 
             head->next=head->next->next;
            head=head->next;
        }
        return dummy->next;
    }
};