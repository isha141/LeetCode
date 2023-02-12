class Solution { 
    private: 
    long long ans=0;
    int solve(int node,vector<int>Adj[],vector<int>&vis,int seats){
        vis[node]=1;
        long long c=1;
        for(auto itr: Adj[node]){
            if(vis[itr]==0){
                c+=solve(itr,Adj,vis,seats);
            }
        }
        int car=c/seats;
        if(c%seats)
            car++;
        if(node!=0)
            ans+=car;
        return c;
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
        solve(0,adj,vis,seats);
        return ans;
    }
};