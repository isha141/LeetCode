class Solution { 
    private:
    void solve(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
                solve(itr,adj,vis);
            }
        }
        return ;
    }
public:
    int findCircleNum(vector<vector<int>>& isconn) {
        int n=isconn.size();
        vector<int>adj[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isconn[i][j]==1){
                adj[i].push_back(j);
                }
            }
        }
        int c=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;++i){
            if(vis[i]==0){
                solve(i,adj,vis);
                    c++;
            }
        }
        return c;
    }
};