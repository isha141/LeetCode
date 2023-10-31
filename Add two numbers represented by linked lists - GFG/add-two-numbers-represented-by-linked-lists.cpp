//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    struct Node *reverse(struct Node *a){
         if(a==NULL) 
         return NULL;
         struct Node *head=a;
         Node *next=a->next;
         a->next=NULL;
         while(next!=NULL){
             Node *p=next->next;
             next->next=head;
             head=next;
             next=p;
         }
         return head;
    }
    struct Node *solve(struct Node *a,struct Node *b){
        int carry=0;
        Node *dummy=new Node(0);
        Node *p=dummy;
        while(a!=NULL || b!=NULL || carry){
            int val=carry;
            if(a){
                val+=a->data;
                a=a->next;
            }
            if(b){
                val+=b->data;
                b=b->next;
            }
            Node *temp=new Node(val%10);
            p->next=temp;
            p=temp;
            carry=val/10;
        }
        return dummy->next;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
         if(first==NULL) return second;
         if(second==NULL) return first;
         first=reverse(first);
         second=reverse(second);
         Node *ans=solve(first,second);
         return reverse(ans);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends