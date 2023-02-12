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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto itr=q.front();
                q.pop(); 
                if(itr==NULL){
                    ans+="#";
                    ans+=',';
                    continue;
                }
                ans+=to_string(itr->val);
                ans+=',';
                if(itr->left)
                    q.push(itr->left);
                else
                    q.push(NULL);
                if(itr->right)
                    q.push(itr->right);
                else
                    q.push(NULL);
            }
        }
        cout<<ans<<":::"<<endl;
        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
              return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode * root=new TreeNode(stoi(str));
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(); 
            bool flag=0;
            while(n--){
                TreeNode * temp=q.front();
                q.pop();
                getline(s,str,','); 
                // if(!flag){
                if(str=="#"){
                    temp->left=NULL;
                    // continue;
                }
                else{
                    temp->left=new TreeNode(stoi(str));
                    q.push(temp->left);
                }
                 getline(s,str,','); 
                    if(str=="#"){
                        temp->right=NULL;
                    }
                    else{
                        temp->right=new TreeNode(stoi(str));
                        q.push(temp->right);
                    }
                }
                flag=!flag;
            }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));