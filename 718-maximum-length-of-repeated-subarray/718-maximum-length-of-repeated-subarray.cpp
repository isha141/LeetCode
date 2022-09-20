class Solution { 
    private:
    int n,m; 
    int ans=0;
    int solve(int i,int j,vector<int>&a,vector<int>&b, vector<vector<int>>&dp)
    {
        if(i>=n || j>=m) return 0; 
         int l=0;
         int r=0; 
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(a[i]==b[j]){
           l= solve(i+1,j+1,a,b,dp)+1; 
            ans=max(ans,l);
        }
        solve(i+1,j,a,b,dp);
        solve(i,j+1,a,b,dp);
        
        return dp[i][j]=l;
    }
public:
    int findLength(vector<int>& a, vector<int>& b) {
        n=a.size(); 
        int ans=0;
        m=b.size(); 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)); 
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                int l=0;
                if(a[i]==b[j]){
                  l=1+dp[i+1][j+1];  
                    ans=max(ans,l);
                } 
                dp[i][j]=l;
            }
        } 
        return ans;
    }
};