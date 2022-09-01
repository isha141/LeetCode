class Solution { 
    private:
    int m,n;
    void solve(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&h)
    {
        if(vis[i][j]==1)
            return ;
        vis[i][j]=1;
        if(i+1<m && h[i][j]<=h[i+1][j]){
            solve(i+1,j,vis,h);
        }
        if(j+1<n && h[i][j]<=h[i][j+1]){
            solve(i,j+1,vis,h);
        }
        if(i-1>=0 && h[i][j]<=h[i-1][j]){
            solve(i-1,j,vis,h);
        }
        if(j-1>=0 && h[i][j]<=h[i][j-1]){
            solve(i,j-1,vis,h);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
         vector<vector<int>>ans;
         m=h.size();
         n=h[0].size(); 
        vector<vector<int>>pac(m,vector<int>(n,0));
        vector<vector<int>>atl(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            if(pac[i][0]==0)
            solve(i,0,pac,h);
        } 
        for(int i=0;i<n;++i){
            if(pac[0][i]==0)
                solve(0,i,pac,h);
        }
        for(int j=0;j<n;++j){
            if(atl[m-1][j]==0){
                solve(m-1,j,atl,h);
            }
        }
        for(int j=0;j<m;++j){
            if(atl[j][n-1]==0)
                solve(j,n-1,atl,h);
        } 
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};