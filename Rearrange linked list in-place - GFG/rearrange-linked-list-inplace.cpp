//{ Driver Code Starts
#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


Node *inPlace(Node *root);
 
void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main() {
	// your code goes here
	int T;
	cin>>T;
 
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Node *res = inPlace(head);
		print(res);
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node *solve(Node *root){
    if(root==NULL)
      return root;
    Node *slow=root;
    Node *fast=root;
    while(slow && fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *reverse(Node *head){
    Node *temp=head->next;
    head->next=NULL;
    while(temp!=NULL){
        Node *p=temp->next;
        temp->next=head;
        head=temp;
        temp=p;
    }
    return head;
}
Node *inPlace(Node *root)
{
 // your code goes here 
        if(root==NULL)
        return root;
        Node *middle=solve(root);
        middle=middle->next;
        middle=reverse(middle);
        Node *head=root;
        while(middle!=NULL){
            Node *temp=middle->next;
            middle->next=head->next;
            head->next=middle;
            head=head->next->next;
            middle=temp;
        }
        head->next=NULL;
        return root;
}
