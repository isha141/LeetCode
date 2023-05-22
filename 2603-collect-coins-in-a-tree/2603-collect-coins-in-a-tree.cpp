class Solution {
public:
    int collectTheCoins(vector<int>& c, vector<vector<int>>& e) { 
          int n=c.size();
          vector<set<int>>adj(n);
          for(auto itr:e){
              adj[itr[0]].insert(itr[1]);
              adj[itr[1]].insert(itr[0]);
          }
        int ans=2*e.size();
          queue<int>leaves;
          for(int i=0;i<n;++i){
            if(adj[i].size()==1 && c[i]==0){
                leaves.push(i);  // leaves which has no coins;
            } 
         } 
        int deleted=0;
          while(!leaves.empty()){
                auto itr=leaves.front();
                leaves.pop();
                if(adj[itr].size()==0)
                      continue;
                int parent=*adj[itr].begin(); 
                adj[parent].erase(itr);
               deleted++;
              adj[itr].erase(parent);
              deleted++; 
              if(adj[parent].size()==1 && c[parent]==0){
                  leaves.push(parent);
              }
          }
           for(int i=0;i<n;++i){
               if(adj[i].size()==1)
                    leaves.push(i);
           }
          int steps=2; 
          while(steps--){
               int t=leaves.size();
              while(t--){
                  auto itr=leaves.front();
                  leaves.pop(); 
                  if(adj[itr].size()==0)
                       continue;
                  int parent=*adj[itr].begin(); 
                  adj[itr].erase(parent);
                  adj[parent].erase(itr);
                  deleted+=2; 
                  if(adj[parent].size()==1)
                  leaves.push(parent);
              }
          }
        
        return ans-deleted;
    }
};