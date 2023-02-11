//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:  
    Node* head=NULL;
     vector<int>ans;
 void find_parent(Node* root,int target, map<Node* ,Node*>&mp){
       if(root==NULL)
          return; 
       if(root->data==target){
           head=root; 
       }
       if(root->left==NULL && root->right==NULL)
       return; 
    //   cout<<root->data<<":::"<<endl;
       find_parent(root->left,target,mp);
       if(root && root->left){
           mp[root->left]=root;
       }
       find_parent(root->right,target,mp);
       if(root && root->right)
          mp[root->right]=root;
       return ;
   } 
   void solve(Node* head,int k,map<Node*,Node*>&mp){
       queue<Node*>q;
       q.push(head); 
       map<Node*,bool>visited;
       int c=0;
       while(c<k && !q.empty()){
           int n=q.size();
           while(n--){
               auto itr=q.front();
               q.pop(); 
               visited[itr]=1;
               if(itr->left && visited.find(itr->left)==visited.end()){
               q.push(itr->left);
               visited[itr->left]=1;
               }
               if(itr->right && visited.find(itr->right)==visited.end()){
                   q.push(itr->right);
                   visited[itr->right]=1;
               }
               if(mp.find(itr)!=mp.end() && visited.find(mp[itr])==visited.end()){
                   q.push(mp[itr]);
                   visited[mp[itr]]=1;
               }
           }
           c++;
       }
       ans.clear();
       while(!q.empty()){
           auto itr=q.front();
           q.pop();
           ans.push_back(itr->data);
       }
   }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        if(root==NULL) return {};
        // Node *head;
        map<Node* ,Node*>mp;
        find_parent(root,target,mp); 
        // cout<<head->data<<">>"<<endl;
        // for(auto itr: mp)
        // cout<<itr.first->data<<" "<<itr.second->data<<endl;
        solve(head,k,mp); 
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends