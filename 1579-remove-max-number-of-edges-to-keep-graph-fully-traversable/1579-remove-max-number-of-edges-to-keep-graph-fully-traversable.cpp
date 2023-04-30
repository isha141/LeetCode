class disjoint{
    vector<int>parent; 
    int size; 
    public:
     disjoint(int n){ 
           parent.resize(n+1,-1);
         for(int i=0;i<=n;++i){
              parent[i]=i;
         } 
         size=n;
     }
     int findparent(int u){
         if(parent[u]==u) return u;
         return parent[u]=findparent(parent[u]);
     }  
    int getsize(){
        return size;
    } 
    void unionbyrank(int u,int v){
        u=findparent(u);
        v=findparent(v);
        if(u==v) return; 
          parent[u]=v;
         size--;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) { 
          disjoint a(n);
          disjoint b(n);
          map<int,vector<pair<int,int>>>ds;
          for(auto itr: e){ 
              ds[itr[0]].push_back({itr[1],itr[2]});
          }
           int total=e.size();
           int used=0;
          vector<pair<int,int>>c=ds[3];
          for(auto itr: c){
              auto u=itr.first;
               auto v=itr.second;
              if(a.findparent(u)!=a.findparent(v)){
                  used++;
                  a.unionbyrank(u,v);
                   b.unionbyrank(u,v);
              }
          }
          for(auto ittr: ds){
              if(ittr.first==3) continue;
              vector<pair<int,int>>c=ittr.second;
              for(auto itr: c){
                  auto u=itr.first;
               auto v=itr.second; 
                if(ittr.first==1){
                 if(a.findparent(u)!=a.findparent(v)){
                  used++;
                  a.unionbyrank(u,v);
                 } 
                }
                 if(ittr.first==2){
                 if(b.findparent(u)!=b.findparent(v)){
                  used++;
                  b.unionbyrank(u,v);
                 } 
                }
             }
          }
        return a.getsize()!=1 || b.getsize()!=1 ?-1: total-used;
    }
};