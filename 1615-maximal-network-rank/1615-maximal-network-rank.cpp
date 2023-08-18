class Solution { 
    private:
    int n;
    int solve(int n1,int n2,set<int>adj[]){
        int count=0; 
         if(adj[n1].size()==0 && adj[n2].size()==0){
              return 0;
        }
       
         if(adj[n1].size() && adj[n2].size()==0){
              return adj[n1].size();
        }  
         if(adj[n1].size()==0){
              return adj[n2].size();
        }
        bool flag=0;
         count=adj[n1].size();
        count+=adj[n2].size();
        for(int i=0;i<=n;++i){
            // if(i!=n1 && i!=n2){
            //     if(adj[i].find(n1)!=adj[i].end() && adj[i].find(n2)!=adj[i].end())
            //         count-=1;
            // }
            if(flag==0 && (i==n1 || i==n2)){
                flag=1;
                if(i==n1){
                    if(adj[i].find(n2)!=adj[i].end()){
                        count-=1;
                    }
                }
                if(i==n2){
                    if(adj[i].find(n1)!=adj[i].end()){
                        count-=1;
                    }
                }
            }
        }
        return count;
        // return 0;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<int>adj[n+1]; 
        this->n=n;
        for(auto itr: roads){
            adj[itr[0]].insert(itr[1]);
            adj[itr[1]].insert(itr[0]);
        }
        int ans=0;
        for(int i=0;i<=n;++i){
              for(int j=i+1;j<=n;++j){ 
                  // cout<<i<<"l;;"<<j<<endl;
                  int temp=solve(i,j,adj);
                  // cout<<i<<"-->"<<j<<"--"<<temp<<endl;
                  ans=max(ans,temp);
                  // cout<<i<<"-->"<<j<<endl;
              }
        }
        return ans;
    }
};