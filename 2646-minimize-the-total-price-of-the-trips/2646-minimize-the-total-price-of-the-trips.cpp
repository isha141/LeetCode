class Solution { 
    private: 
    int dfs(int u,vector<int>adj[],int v,map<int,int>&mp,int p=-1){
         if(u==v){
             mp[u]++;
        return 1;} 
        for(auto itr: adj[u]){
            if(itr==p)  continue;
            if(dfs(itr,adj,v,mp,u)){
                mp[u]++;
                return 1;
            }
        }
        return 0;
    } 
      pair<int,int> dfs2(int node,int par,vector<int>&p,vector<int>adj[],map<int,int>&mp){
        int consider=(p[node]/2)*mp[node];
        int dont_consider=(p[node])*mp[node];
          for(auto itr: adj[node]){
              if(itr!=par){
                    auto iit=dfs2(itr,node,p,adj,mp);
                  consider+=iit.second;
                  dont_consider+=min(iit.first,iit.second);
              }
          }
        return {consider,dont_consider};
   }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& e, vector<int>& p, vector<vector<int>>& t) { 
          vector<int>adj[n+1]; 
         map<int,int>mp;
          for(int i=0;i<e.size();++i){
              adj[e[i][0]].push_back(e[i][1]);
              adj[e[i][1]].push_back(e[i][0]);
          }
          for(auto itr: t){
              dfs(itr[0],adj,itr[1],mp);
          }   
        // for(auto itr: mp) 
        //     cout<<itr.first<<",,"<<itr.second<<endl;
          auto itr=dfs2(0,-1,p,adj,mp); 
        // cout<<itr.first<<":::"<<itr.second<<endl;
         return min(itr.first,itr.second);
    }
};