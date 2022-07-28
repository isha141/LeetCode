/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string ans="";
    queue<TreeNode* >q;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        if(root==NULL) return "";
        q.push(root);
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop(); 
            if(temp==NULL){
                ans+='#'; 
                ans+=','; 
                continue;
           }
            else
            ans+=to_string(temp->val);
                ans+=','; 
            if(temp->left)
                q.push(temp->left);
            else
                q.push(NULL);
            if(temp->right)
                q.push(temp->right);
            else
                q.push(NULL);
        }  
        // cout<<ans<<" ";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { 
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode *>q;
        TreeNode *root=new TreeNode(stoi(str));
        // getline(s,str,',');  
        q.push(root);
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            getline(s,str,',');   
            if(str=="#")
                temp->left=NULL;
            else{
                temp->left=new TreeNode(stoi(str));
                q.push(temp->left);
            }
            getline(s,str,',');  
            if(str=="#")
              temp->right=NULL;
            else{
                temp->right=new TreeNode(stoi(str));
                q.push(temp->right);
            }   
        }
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));