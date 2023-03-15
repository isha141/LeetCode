/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { 
    private: 
    vector<string>ds;
    bool solve(TreeNode *root){
        if(root==NULL) return 1;
        int level=0; 
        queue<TreeNode * >q;
        q.push(root);
        while(!q.empty()){ 
             int n=q.size(); 
            string s="";
            while(n--){ 
            auto itr=q.front();
                q.pop(); 
            if(itr==NULL) { 
                s+='#'; continue; 
            }
             s+=to_string(itr->val);
            if(itr->left)
                q.push(itr->left); 
            else
                q.push(NULL);
            if(itr->right)
                q.push(itr->right); 
            else 
                q.push(NULL);
        } 
            ds.push_back(s);
        }
        return 1;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return 1;
        solve(root);  
        bool flag=0;  
        // for(auto itr: ds) cout<<itr<<" ";
        // cout<<"*****";
        for(auto i=0;i<ds.size()-2;++i){
            // cout<<ds[i]<<endl;
              for(auto itr: ds[i]){
                  if(itr=='#') return 0;
              }
        }
        string temp=ds[ds.size()-2]; 
        // cout<<temp<<"::";
        for(int i=0;i<temp.size();++i){
            if(temp[i]!='#' && flag) 
                return 0;
            else if(temp[i]=='#'){
                flag=1;
            }
        }
        return 1;
    }
    
};