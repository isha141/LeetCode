class Solution { 
    private:
    int solve(int node,vector<vector<int>>&s,vector<int>&vis,int n){
        int ans=0;
        for(int i=0;i<n;++i){
            if(!vis[i] &&  (s[node][0]==s[i][0] || s[node][1]==s[i][1])){
                vis[i]=1;
                ans+=1+solve(i,s,vis,n);
            }
        }
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& s) {
       int n=s.size();
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                ans+=solve(i,s,vis,n)-1;
            }
        }
        return ans;
    }
};