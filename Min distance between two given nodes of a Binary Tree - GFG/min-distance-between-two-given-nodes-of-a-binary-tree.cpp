//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    private:
    map<Node*,Node*>mp;
    Node *head=NULL;
    void findparent(Node *root,int a){
        if(root==NULL)
          return;
        if(root->data==a){
            head=root;
        }
        if(root->left==NULL && root->right==NULL)
          return ;
        findparent(root->left,a);
        if(root && root->left){
            mp[root->left]=root;
        }
        if(root->right){
            mp[root->right]=root;
        }
        findparent(root->right,a);
    }
    public:
    int findDist(Node* root, int a, int b) {
        // Your code here
        queue<pair<Node*,int>>q;
        int ans=INT_MAX;
        findparent(root,a);
        q.push({head,0});
        map<Node*,int>dis;
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            Node* root=itr.first;
            int c=itr.second;
            if(root->data==b){
                ans=min(ans,itr.second);
            }
            if(root->left && dis.find(root->left)==dis.end()){
                dis[root->left]=c+1;
                q.push({root->left,c+1});
            }
            else if(dis[root->left]>c+1){
                dis[root->left]=c+1;
                q.push({root->left,c+1});
            }
            if(root->right && dis.find(root->right)==dis.end()){
                dis[root->right]=c+1;
                q.push({root->right,c+1});
            }
            else if(dis[root->right]>c+1){
                dis[root->right]=c+1;
                q.push({root,c+1});
            }
            if(mp.find(root)!=mp.end() && dis.find(mp[root])==dis.end()){
                   q.push({mp[root],c+1});
                   dis[mp[root]]=c+1;
            }
            else if(mp.find(root)!=mp.end() && dis[mp[root]]>c+1){
                   q.push({mp[root],c+1});
                   dis[mp[root]]=c+1;
            }
        }
    return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends