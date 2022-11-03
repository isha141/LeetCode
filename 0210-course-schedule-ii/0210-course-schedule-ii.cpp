class Solution { 
    private:
bool solve(int node,vector<int>adj[],stack<int>&s,vector<int>&vis,vector<int>dfsvis){
        vis[node]=1;
    dfsvis[node]=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
                if(solve(itr,adj,s,vis,dfsvis))
                    return 1;
            }
            else if(dfsvis[itr])
                return 1;
        }
        dfsvis[node]=0;
        s.push(node);
        return 0;
    }
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
         vector<int> ans;
        stack<int>s;
        int count=0; 
        vector<int>dfsvis(num,0);
        vector<int>adj[num];
        for(int i=0;i<pre.size();++i){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>vis(num+1,0);
        for(int i=0;i<num;++i){
            if(vis[i]==0){
                // count++;
                if(solve(i,adj,s,vis,dfsvis))
                    return {};
            }
        }
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
            return ans;
    }
};