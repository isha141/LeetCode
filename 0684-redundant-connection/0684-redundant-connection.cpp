class kruskal{
     public:
      vector<int>parent;
      vector<int>rank;
     kruskal(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;++i){
                parent[i]=i;
                 rank[i]=0;
            }
     }
    int findparent(int u){
          if(u==parent[u])
                return u;
          return parent[u]=findparent(parent[u]);
    }
    void unionByRank(int u,int v){
         u=findparent(u);
         v=findparent(v);
         if(rank[u]<rank[v]){
             rank[v]+=1;
              parent[u]=v;
         }
        else{
              rank[u]+=1;
              parent[v]=u;
        }
    }
};
class Solution { 
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
           vector<int>ans;
           int n=e.size();
           kruskal adj(n+2);
           if(e.size()==0){
                 return ans;
           }
           for(auto itr: e){
                int u=itr[0];
                int v=itr[1];
               if(adj.findparent(u)==adj.findparent(v)){
                     ans.push_back(u);
                     ans.push_back(v);
               }
               else{
                   adj.unionByRank(u,v);
               }
           }
          return ans;
    }
};