class Solution { 
    private:
    vector<vector<int>>adj;
    vector<int>ans;
    string s; 
    private:
    vector<int> solve(int node,int par){
        vector<int>cnt(32,0);
        for(auto itr: adj[node]){
            if(itr==par) continue; 
            vector<int>ds=solve(itr,node);
            for(int i=0;i<32;++i)
                cnt[i]+=ds[i];
        }
        cnt[s[node]-'a']++;
        ans[node]=cnt[s[node]-'a'];
        return cnt;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string labels) {
        adj.resize(n);
        ans.resize(n);
        s=labels;
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        solve(0,-1);
        return ans;
    }
};