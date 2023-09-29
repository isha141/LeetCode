class disjoint{
    public:
    vector<int>rank;
    vector<int>parent;
    disjoint(int n){
        rank.resize(n,1);
        parent.resize(n,0);
        for(int i=0;i<n;++i)
            parent[i]=i;
    }
    int findparent(int u){
        if(parent[u]==u)
             return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionByRank(int u,int v){
        u=findparent(u);
        v=findparent(v);
        if(u==v)
              return;
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]+=rank[u];
        }
        else{
            parent[v]=u;
            rank[u]+=rank[v];
        }
    }
};
class Solution {
    private:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool isvalid(int i,int j){
        return (i>=0 && j>=0 && i<n && j<m);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
          n=grid.size();
          m=grid[0].size();
          disjoint ds(n*m);
          for(int i=0;i<n;++i){
              for(int j=0;j<m;++j){
                  if(grid[i][j]==1){
                      for(int k=0;k<4;++k){
                          int nx=dx[k]+i;
                          int ny=dy[k]+j;
                          if(isvalid(nx,ny) && grid[nx][ny]==1){
                              int newIndex=i*m+j;
                              int adjIndex=nx*m+ny;
                              ds.unionByRank(newIndex,adjIndex);   
                          }
                      }
                  }
              }
          }
          int ans=0;
          for(int i=0;i<n;++i){
              for(int j=0;j<m;++j){
                  if(grid[i][j]==1)
                      continue;
                  set<int>s;
                  int temp=0;
                  for(int k=0;k<4;++k){
                      int nx=dx[k]+i;
                      int ny=dy[k]+j;
                      if(isvalid(nx,ny) && grid[nx][ny]==1){
                          int adjVal=nx*m+ny;
                          adjVal=ds.findparent(adjVal);
                          if(s.find(adjVal)==s.end()){
                              s.insert(adjVal);
                              temp+=ds.rank[adjVal];
                          }
                      }
                  }
                  ans=max(ans,temp+1);
              }
          }
          return ans==0?(n*m):ans;
    }
};