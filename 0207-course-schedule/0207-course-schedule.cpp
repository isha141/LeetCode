class Solution {
    private:
    bool solve(int i,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis){
        dfsvis[i]=1;
        vis[i]=1;
        for(auto itr: adj[i]){
            if(vis[itr]==0){
                if(solve(itr,adj,vis,dfsvis))
                    return 1;
            }
            else if(dfsvis[itr])
                return 1;
        }
        dfsvis[i]=0;
        return 0;
    }
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int>adj[num];
        for(int i=0;i<pre.size();++i)
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<int>vis(num+1,0);
        vector<int>dfsvis(num+1,0);
        for(int i=0;i<num;++i){
            if(vis[i]==0){
                if(solve(i,adj,vis,dfsvis))
                    return 0;
            }
        }
        return 1;
    }
};