class Solution { 
    private: 
    long long ans=0;
    long long solve(int node,vector<int>adj[],int seats,vector<int>&vis,int dis){
          vis[node]=1;
         int people=1;
         for(auto itr: adj[node]){
               if(!vis[itr]){
                    people+=solve(itr,adj,seats,vis,dis+1);
               }
         }
         if(node!=0){
             ans+=(people+seats-1)/seats; 
         }
           return people;
     }
public:
    long long minimumFuelCost(vector<vector<int>>& r, int seats) { 
          int n=r.size();
          vector<int>adj[n+1];
           for(int i=0;i<n;++i){
                 adj[r[i][0]].push_back(r[i][1]);
                 adj[r[i][1]].push_back(r[i][0]);
           } 
          vector<int>vis(n+1,0);
           solve(0,adj,seats,vis,0); 
        return ans;
    }
};