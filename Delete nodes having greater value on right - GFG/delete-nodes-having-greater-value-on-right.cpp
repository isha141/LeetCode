//{ Driver Code Starts
#include<bits/stdc++.h>

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


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
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
class Solution
{
    private:
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
    public:
    Node *compute(Node *head)
    {
        if(head==NULL)
          return head;
        Node *root=head;
        head=reverse(head);
        Node *dummy=new Node(0);
        Node *curr=head;
        dummy->next=curr;
        int maxi=head->data;
        head=head->next;
        while(head!=NULL){
            if(head->data>=maxi){
                curr->next=head;
                curr=curr->next;
                maxi=max(maxi,head->data);
            }
            head=head->next;
        }
        curr->next=NULL;
        head=reverse(dummy->next);
        return head;
    }
};
   


//{ Driver Code Starts.

int main()
{
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
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends