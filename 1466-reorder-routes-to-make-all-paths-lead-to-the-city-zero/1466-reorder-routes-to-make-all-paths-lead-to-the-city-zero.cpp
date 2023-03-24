class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<con.size();++i){
            adj[con[i][0]].push_back({con[i][1],1});
            adj[con[i][1]].push_back({con[i][0],0});
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(n,0);
        int ans=0;
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            ans+=itr.second;
            vis[itr.first]=1;
            for(auto iitr: adj[itr.first]){ 
                // cout<<itr.first<<"::: "<<iitr.first<<",,"<<iitr.second<<endl;
                   if(vis[iitr.first]) continue;
                q.push(iitr);
            }
        }
        return ans;
    }
};