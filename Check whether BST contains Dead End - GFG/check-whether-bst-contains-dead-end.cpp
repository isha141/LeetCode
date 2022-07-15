// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */ 
void store(Node *root,unordered_set<int >&all_node,unordered_set<int>&leaf_node)
{
    if(root==NULL)
    return ;
    if(root->left==NULL && root->right==NULL)
      leaf_node.insert(root->data);
    else
    all_node.insert(root->data);
    store(root->left,all_node,leaf_node);
    store(root->right,all_node,leaf_node);
}
bool isDeadEnd(Node *root)
{
    //Your code here 
    unordered_set<int>all_node,leaf_node;
    store(root,all_node,leaf_node); 
    all_node.insert(0);
    
    for(auto itr=leaf_node.begin();itr!=leaf_node.end();itr++){
        int i=(*itr);
        if(all_node.find(i+1)!=all_node.end() && all_node.find(i-1)!=all_node.end())
        return true;
    }
    return 0;
    
}