//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
int solve(struct Node *root){
    if(root==NULL)
      return 0;
    int l=solve(root->left);
    int r=solve(root->right);
    return (l+r)+1;
}
pair<int,int> ok(Node *root,int count){
    int m1=0;
    int m2=0;
    int i=0;
    while(root!=NULL){
        //  cout<<i<<";;"<<endl;
        if(root->left==NULL){
            i+=1;
            if(i==count){
                m1=root->data;
            }
            if(i==count+1){
                m2=root->data;
            }
            root=root->right;
        }
        else{
            Node *curr=root->left;
            while(curr->right!=NULL && curr->right!=root){
                curr=curr->right;
            }
            if(curr->right==NULL){
                curr->right=root;
                root=root->left;
            }
            else{
                i+=1;
                if(i==count){
                    m1=root->data;
                }
               if(i==count+1){
                  m2=root->data;
                }
                root=root->right;
                curr->right=NULL;
            }
        }
    }
    return {m1,m2};
}
float findMedian(struct Node *root)
{
      //Code here
      int cnt=solve(root);
      pair<int,int>itt;
      itt=ok(root,cnt/2);
    //   cout<<itt.first<<";;"<<itt.second<<endl;
      if(cnt%2){
          return (double)itt.second;
      }
      else{
          return (double)(itt.first+itt.second)/2.0;
      }
}



