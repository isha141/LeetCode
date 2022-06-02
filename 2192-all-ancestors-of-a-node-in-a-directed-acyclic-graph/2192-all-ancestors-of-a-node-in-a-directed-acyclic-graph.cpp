class Solution { 
    private:
    void bfs(int node,vector<int>adj[],vector<vector<int>>&ans,vector<int>&ds,int n)
    { 
        queue<int>q;
        q.push(node); 
        vector<int>vis(n,0);
        while(!q.empty()){
            int temp=q.front();
            q.pop(); 
        for(auto itr: adj[temp])
        {   
            if(vis[itr]==0){
            q.push(itr); 
            ds.push_back(itr);
            vis[itr]=1;
            }
        }
    }
}
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        vector<int>adj[n];
        for(auto itr: edges)
        {
           adj[itr[1]].push_back(itr[0]);
        }  
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) 
            { 
                vis[i]=1;
                vector<int>ds;
                bfs(i,adj,ans,ds,n);  
                if(ds.size()==0)
                    ans.push_back({});
                else{
                    sort(ds.begin(),ds.end());
                      ans.push_back(ds);
                }
              
            }
            
        }
        return ans;
    }
};