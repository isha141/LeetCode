//{ Driver Code Starts
// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

long long unsigned int decimalValue(struct Node *head);

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

        cout << decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

Node *reverse(Node *head){
      if(head==NULL || head->next==NULL)
        return head;
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
long long unsigned int decimalValue(Node *head)
{
   // Your Code Here
       head=reverse(head);
      long long unsigned int ans=0;
      long mod=1e9+7;
      int k=0;
      long temp=1;
      while(head!=NULL){
         long long res=temp*head->data;
         temp*=2;
         temp%=mod;
         ans=(ans%mod+res%mod)%mod; 
         head=head->next;
      }
    //   cout<<endl;
      return ans;
}
