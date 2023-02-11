/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:  
    TreeNode* head;
    vector<int>ans;
 void find_parent(TreeNode* root,TreeNode *target, map<TreeNode* ,TreeNode*>&mp){
       if(root==NULL)
          return; 
       if(target==root){
           head=root; 
       }
       if(root->left==NULL && root->right==NULL)
       return; 
       // cout<<root->val<<":::"<<endl;
       find_parent(root->left,target,mp);
       if(root && root->left){
           mp[root->left]=root;
       }
     find_parent(root->right,target,mp);
       if(root && root->right)
          mp[root->right]=root;
       return ;
   } 
   void solve(TreeNode* target,int k,map<TreeNode*,TreeNode*>&mp){
       queue<TreeNode*>q;
       q.push(head);  
       // cout<<head->val<<"..."<<endl;
       map<TreeNode*,bool>visited;
       int c=0; 
       visited[head]=1;
       while(c<k && !q.empty()){
           int n=q.size();
           while(n--){
               auto itr=q.front();
               q.pop(); 
               // cout<<itr->val<<"::"<<endl;
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
       while(!q.empty()){
           auto itr=q.front();
           q.pop();
           ans.push_back(itr->val);
       }
   }
public:

    vector <int> distanceK(TreeNode* root, TreeNode *target , int k)
    {
        // return the sorted vector of all nodes at k dist
        if(root==NULL) return {};
        TreeNode *head;
        map<TreeNode* ,TreeNode*>mp;
        find_parent(root,target,mp); 
        // for(auto itr: mp)
        // cout<<itr.first->val<<" "<<itr.second->val<<endl;
        solve(target,k,mp);
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
//     }
// };