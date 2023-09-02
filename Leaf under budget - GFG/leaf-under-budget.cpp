//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
    private:
    int solve(Node *root,int k){
        if(root==NULL)
          return 0;
        queue<Node *>q;
        q.push(root);
        int level=1;
        int tot=0;
        int c=0;
        vector<int>ans;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                if(itr->left==NULL && itr->right==NULL){
                    // cout<<itr->data<<";;;"<<level<<endl;
                    ans.push_back(level);
                }
                if(itr->left){
                    q.push(itr->left);
                }
                if(itr->right){
                    q.push(itr->right);
                }
            }
            level+=1;
        }
        sort(ans.begin(),ans.end());
        for(auto itr: ans){
            //   cout<<itr<<";;";
            if((itr+tot)<=k){
                c+=1;
                tot+=itr;
            }
        }
        return c;
    }
public:
    int getCount(Node *root, int k)
    {
        //code here
        if(root==NULL) return 0;
        return solve(root,k);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        int res = obj.getCount(root, k);
        cout << res << "\n";
    }
    return 0;
}

// } Driver Code Ends