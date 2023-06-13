class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
          if(des.size()==0)
                return NULL; 
        set<TreeNode *>s;
          map<int,TreeNode *>mp,parent;
          int n=des.size();
          for(int i=0;i<n;++i){
                int par=des[i][0];
                int curr=des[i][1]; 
                // cout<<par<<";;"<<curr<<endl;
                TreeNode *current,*paren;
                if(mp.find(curr)!=mp.end()){
                      current=mp[curr];
                    // cout<<"cuur->"<<" "<<current->val;
                }     
                else{
                     current=new TreeNode(curr);
                }
                if(mp.find(par)!=mp.end()){
                    paren=mp[par]; 
                    // cout<<"paren"<<paren->val<<"***";
                }
                else{
                    paren=new TreeNode(par);
                } 
                if(des[i][2]==1){
                    paren->left=current;
                }
                else{
                    paren->right=current;
                }
                mp[curr]=current; 
                mp[par]=paren; 
                parent[curr]=current;
                 s.insert(current);
                s.insert(paren);
              // cout<<"***********0"<<endl;
         } 
        TreeNode *root;
         for(auto itr=s.begin();itr!=s.end();++itr){
             if(parent.find((*itr)->val)==parent.end()){
                 root=*itr;
             }
         }
        return root;
    }
};