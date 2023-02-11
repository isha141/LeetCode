//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution { 
    private:
    map<Node*,Node*>mp;
    Node * head;
    void find_parent(Node* root,int target){
        if(root==NULL)
          return ;
          if(root->data==target){
              head=root;
          }
          if(root->left==NULL && root->right==NULL)
            return ;
            find_parent(root->left,target);
            find_parent(root->right,target);
            if(root->left)
            mp[root->left]=root;
            if(root->right)
            mp[root->right]=root;
            return ;
    } 
    int solve(Node* root){
        queue<Node*>q;
        q.push(head);
        int c=-1; 
        map<Node*,bool>vis;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto itr=q.front();
                q.pop();
                vis[itr]=1;
                if(itr->left && vis.find(itr->left)==vis.end()){
                    q.push(itr->left);
                    vis[itr->left]=1;
                }
                if(itr->right && vis.find(itr->right)==vis.end()){
                    q.push(itr->right);
                    vis[itr->right]=1;
                }
                if(mp.find(itr)!=mp.end() && vis.find(mp[itr])==vis.end()){
                    vis[mp[itr]]=1;
                    q.push(mp[itr]);
                }
            }
            c++;
        }
        return c;
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here  
        if(root==NULL)
          return 0;
        find_parent(root,target);   
        return solve(root);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends