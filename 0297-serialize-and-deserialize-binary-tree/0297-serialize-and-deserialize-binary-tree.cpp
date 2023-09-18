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
        string ans="";
        if(root==NULL)
              return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it==NULL){
                ans+="#";
                ans+=',';
              continue;
            }
            ans+=to_string(it->val);
            ans+=",";
            if(it->left){
                q.push(it->left);
            }
            else{
                q.push(NULL);
            }
            if(it->right){
                q.push(it->right);
            }
            else{
                q.push(NULL);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
          if(data.size()==0){
              return NULL;
          }
          stringstream s(data);
          string word;
          getline (s,word,',');
          TreeNode *root=new TreeNode(stoi(word));
          queue<TreeNode*>q;
          q.push(root);
          while(!q.empty()){
              auto itr=q.front();
              q.pop();
              getline(s,word,',');
              if(word=="#"){
                  itr->left=NULL;
              }
              else{
                  itr->left=new TreeNode(stoi(word));
                  q.push(itr->left);
              }
              getline(s,word,',');
              if(word=="#"){
                  itr->right=NULL;
              }
              else{
                  itr->right=new TreeNode(stoi(word));
                  q.push(itr->right);
              }
          }
           return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));