class Solution {
    private:
    int solve(int node,vector<int>adj[],vector<bool>&has,int parent){
        int total=0;
        for(auto itr: adj[node]){
            if(itr==parent)
                continue;
            total+=solve(itr,adj,has,node);
        }
        if(node!=0  &&  (total>0 || has[node]==true))
            total+=2;
        return total;
    }
public:
    int minTime(int n, vector<vector<int>>& e, vector<bool>& has) {
        vector<int>adj[n+1];
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
            
        }
        return solve(0,adj,has,0);
    }
};