class Solution { 
    long ans=0;
    int dfs(int node,vector<int>&vis,vector<int>adj[],int seat){
        vis[node]=1;
        long long count=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
                count+=dfs(itr,vis,adj,seat);
            }
        } 
        
        int car=count/seat;
        if(count%seat)
            car++;
        if(node!=0)
            ans+=car;
        return count;
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
        dfs(0,vis,adj,seats); 
        return ans;
    }
};