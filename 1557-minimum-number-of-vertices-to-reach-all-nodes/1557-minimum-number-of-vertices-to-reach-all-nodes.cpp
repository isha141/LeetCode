class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<int>adj[n];
        vector<int>indeg(n,0);
         for(auto itr: e){
             adj[itr[0]].push_back(itr[1]);
             indeg[itr[1]]++;
         }
          queue<int>q;
         vector<int>ans; 
        vector<int>vis(n,0);
          for(int i=0;i<n;++i){
              if(indeg[i]==0)
                  q.push(i);
          }
           while(!q.empty()){
               auto itr=q.front();
                q.pop();
               if(!vis[itr]){
                    ans.push_back(itr);
                    vis[itr]=1;
                   for(auto iit: adj[itr]){
                        indeg[iit]--;
                       if(indeg[iit]==0)
                            q.push(iit);
                        vis[iit]=1;
                   }
               }
           }
          return ans;
    }
};