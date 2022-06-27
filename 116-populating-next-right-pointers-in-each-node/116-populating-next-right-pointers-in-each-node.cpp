class Solution {
public:
    Node* connect(Node* root) {
        vector<Node *>v;
        if(root==NULL)
            return root; 
        Node *head=root;
        queue<Node *>q;
        q.push(root); 
     //  vector<Node *>v;
        while(!q.empty()){
           int n=q.size();
            while(n--){ 
                Node *temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            } 
            v.push_back(NULL);
        } 
        // for(auto itr: v)
        // {
        //     if(itr!=NULL)
        //         cout<<itr->val<<" ";
        //     else
        //         cout<<"NULL"<<" ";
        // }
       for(int i=0;i<v.size()-1;++i){
           if(v[i]!=NULL){
               v[i]->next=v[i+1];
           }
               else{
                   continue;
               }
       }
       return head; 
    } 
};