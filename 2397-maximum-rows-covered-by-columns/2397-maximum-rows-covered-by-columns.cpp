class Solution { 
    int ans=0; 
    int n,m;
    void solve(int ind,vector<vector<int>>& mat,int num,vector<int>&vis)
    {
         if(num==0){ 
            int c=0;
            for(int i=0;i<n;++i){ 
                bool flag=1;
                for(int j=0;j<m;++j){
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
        for(int j=ind;j<m;++j){
            vis[j]=1;
            solve(j+1,mat,num-1,vis);
            vis[j]=0;
        }
    }
public:
    int maximumRows(vector<vector<int>>& mat, int num) {
         n=mat.size();
         m=mat[0].size();
       vector<int>vis(m,0); 
        solve(0,mat,num,vis);
        return ans;
    }
};