class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& e) {
          vector<int>adj[n+1];
          for(int i=0;i<e.size();++i){
              adj[e[i][0]].push_back(e[i][1]);
              adj[e[i][1]].push_back(e[i][0]);
          }
          int ans=1e9;
         for(int i=0;i<=n;++i){
             vector<int>dis(n+1,1e9);
             vector<int>par(n+1,-1); 
             queue<int>q;
              dis[i]=0; 
              q.push(i); 
             while(!q.empty()){ 
                   auto node=q.front();
                   q.pop();  
                 for(auto itr: adj[node]){
                 if(dis[itr]==1e9){
                     dis[itr]=dis[node]+1;
                     par[itr]=node; 
                     q.push(itr);
                 }
                 else if(par[itr]!=node && par[node]!=itr){
                     ans=min(ans,dis[itr]+1+dis[node]);
                 }
              }
            }
             // cout<<endl;
         } 
        return ans==1e9?-1:ans;
    }
};