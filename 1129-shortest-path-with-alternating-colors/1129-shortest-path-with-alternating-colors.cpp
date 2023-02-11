struct cmp{
    public:
    int node;
    int value;
    int color;
};
class Solution { 
    private:
    vector<int>ans;
    int n;
    void solve(int node,vector<pair<int,int>>red[]){
         queue<cmp>q;
        q.push({node,0,-1});
        // int ans=INT_MAX; 
        int c=0;
        ans[0]=0;
        vector<vector<int>>vis(n,vector<int>(2,0));
        vis[node][0]=1;
        vis[node][1]=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto itr=q.front();
                q.pop();  
                int nodes=itr.node; 
                int dis=itr.value;
                // if(nodes==x){
                //     ans=min(ans,dis);
                // }
                int prevcol=itr.color; 
                for(auto [nei,col]: red[nodes]){
                     if(!vis[nei][col] && col!=prevcol){
                         q.push({nei,dis+1,col}); 
                         vis[nei][col]=1;
                        if(ans[nei]==-1)
                             ans[nei]=dis+1;
                     }
                }                
                
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {  
        ans.resize(n,-1);
        this->n=n;
        vector<pair<int,int>>red[n];
        for(int i=0;i<redEdges.size();++i){
            red[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        for(int i=0;i<blueEdges.size();++i){
            red[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        } 
        solve(0,red);
        // for(int i=1;i<n;++i){  
        //     int temp=solve(0,i,red);
        //     ans[i]=temp;
        // }
        return ans;
        
    }
};