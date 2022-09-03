class Solution { 
    private:
    int m,n;  
    int ans=0;
    void solve(int i,vector<vector<int>>& mat, int cols,vector<int>&vis)
    {
        if(cols==0){ 
            int c=0;
            for(int i=0;i<m;++i){ 
                bool flag=1;
                for(int j=0;j<n;++j){
                    if(mat[i][j]==1 && !vis[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    c++;
            }
            ans=max(ans,c);
        }
        for(int j=i;j<n;++j){
            vis[j]=1;
            solve(j+1,mat,cols-1,vis);
            vis[j]=0;
        }
    }
    
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
         m=mat.size();
         n=mat[0].size();
        vector<int>vis(n,0);
        solve(0,mat,cols,vis); 
        return ans;
    }
};